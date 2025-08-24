#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "decrypt_chunk.hpp"

bool DecryptMetadata(const std::vector<unsigned char>& encryptedData,
                     std::vector<unsigned char>&       decryptedData)
{
	if (encryptedData.size() < 8)
	{
		std::cout << "File too small to be valid metadata" << std::endl;
		return false;
	}

	// DA FE 57 13 F4
	uint32_t magic = *reinterpret_cast<const uint32_t*>(encryptedData.data());
	if (magic != 0x1357FEDA)
	{
		std::cout << "Invalid magic number: " << std::hex << magic << std::endl;
		return false;
	}

	// Get data size
	uint32_t encryptedSize = *reinterpret_cast<const uint32_t*>(encryptedData.data() + 4);
	std::cout << "Encrypted data size: " << encryptedSize << " bytes" << std::endl;
	std::cout << "Total file size: " << encryptedData.size() << " bytes" << std::endl;

	// Calculate actual header size from file structure
	size_t actualHeaderSize = encryptedData.size() - encryptedSize;
	std::cout << "Header size: " << actualHeaderSize << " bytes (0x" << std::hex << actualHeaderSize << std::dec << ")" << std::endl;

	if (encryptedSize == 0 || encryptedSize > encryptedData.size())
	{
		std::cout << "Invalid encrypted size: " << encryptedSize << " (file size: " << encryptedData.size() << ")" << std::endl;
		return false;
	}

	if (actualHeaderSize < 0x108 + 64)
	{
		std::cout << "Header too small for bytecode extraction" << std::endl;
		return false;
	}

	// sub_18091BD50((_DWORD)MetaDataFile + 0x108, 64, (_DWORD)MetaDataFile + 8, v2 + (_DWORD)MetaDataFile + 0x148, v8);
	// Extract bytecode from offset 0x108 size 64
	const unsigned char* bytecode = encryptedData.data() + 0x108;
	// Extract key from offset 8 size 256
	const unsigned char* key = encryptedData.data() + 8;

	// Calculate the actual data start offset
	size_t dataStartOffset = actualHeaderSize;
	std::cout << "Data starts at offset: 0x" << std::hex << dataStartOffset << std::dec << std::endl;

	// Copy encrypted data to working buffer
	std::vector<unsigned char> workingData(encryptedData.data() + dataStartOffset,
	                                       encryptedData.data() + dataStartOffset + encryptedSize);

	// Decrypt in 64 byte chunks
	for (size_t offset = 0; offset < encryptedSize; offset += 64)
	{
		size_t chunkSize = std::min(64ULL, encryptedSize - offset);
		DecryptChunk(bytecode, 64, key, workingData.data() + offset, chunkSize);
	}

	// if ( (unsigned int)sub_180A52AC0((_QWORD *)MetaDataFile + 0x29, (__int64)"CODEPHIL", 8uLL) )
	// Verify "CODEPHIL" signature at the beginning of decrypted data
	if (workingData.size() >= 8 && memcmp(workingData.data(), "CODEPHIL", 8) != 0)
	{
		std::cout << "Warning: 'CODEPHIL' signature not found at start of decrypted data" << std::endl;
		// Print what we found instead
		std::cout << "Found: ";
		for (int i = 0; i < 8 && i < workingData.size(); i++)
		{
			if (isprint(workingData[i]))
			{
				std::cout << workingData[i];
			}
			else
			{
				std::cout << "\\x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(workingData[i]);
			}
		}
		std::cout << std::endl;
	}

	// skip the "CODEPHIL" signature and return the decrypted data
	if (workingData.size() >= 8)
	{
		decryptedData.assign(workingData.begin() + 8, workingData.end());
	}
	else
	{
		decryptedData = workingData;
	}

	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Usage: " << argv[0] << " <encrypted_metadata.dat> <output_metadata.dat>" << std::endl;
		return 1;
	}

	// Read encrypted file
	std::ifstream inFile(argv[1], std::ios::binary);
	if (!inFile)
	{
		std::cout << "Could not open input file: " << argv[1] << std::endl;
		return 1;
	}

	std::vector<unsigned char> encryptedData((std::istreambuf_iterator<char>(inFile)),
	                                         std::istreambuf_iterator<char>());
	inFile.close();

	std::cout << "Loaded " << encryptedData.size() << " bytes from " << argv[1] << std::endl;

	// Decrypt the data
	std::vector<unsigned char> decryptedData;
	if (!DecryptMetadata(encryptedData, decryptedData))
	{
		std::cout << "Decryption failed" << std::endl;
		return 1;
	}

	std::cout << "Decrypted " << decryptedData.size() << " bytes" << std::endl;

	// Write decrypted file
	std::ofstream outFile(argv[2], std::ios::binary);
	if (!outFile)
	{
		std::cout << "Could not create output file: " << argv[2] << std::endl;
		return 1;
	}

	outFile.write(reinterpret_cast<const char*>(decryptedData.data()), decryptedData.size());
	outFile.close();

	std::cout << "Decrypted metadata saved to " << argv[2] << std::endl;

	// Check if its a valid IL2CPP metadata file
	if (decryptedData.size() >= 4)
	{
		uint32_t currentMagic = *reinterpret_cast<const uint32_t*>(decryptedData.data());
		std::cout << "First 4 bytes of decrypted data: 0x" << std::hex << currentMagic << std::endl;

		if (currentMagic == 0xFAB11BAF)
		{
			std::cout << "AF 1B B1 FA found!" << std::endl;
		}
	}

	return 0;
}
