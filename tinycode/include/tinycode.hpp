#pragma once

#include <tinycode/decoding.hpp>
#include <tinycode/encoding.hpp>
#include <tinycode/tree.hpp>

#include <cmath>
#include <cstdint>
#include <string>
#include <unordered_set>
#include <vector>

namespace TinyCode {
	namespace Debug {
		std::string Print(uint64_t size, std::vector<uint8_t>& bytes, bool with_delimiter);
		std::string PrintAsCArray(uint64_t size, std::vector<uint8_t>& bytes);
		std::string PrintAsCArray(std::vector<uint8_t>& bytes);
		bool AreIdentical(std::vector<uint8_t>& bytes1, std::vector<uint8_t>& bytes2, uint64_t size);
	}

	class Parser {
	public:
		Parser(uint8_t* buf, size_t size);
		std::vector<std::string> GetInstructionStrings();

	private:
		std::vector<std::string> instructions;
	};

	namespace Wasm {
		void Optimize(std::vector<uint8_t>& in, std::vector<uint8_t>& out, std::unordered_set<std::string> kept_names);
		uint64_t OptimizeTiny(
			std::vector<uint8_t>& in, std::unordered_set<std::string> kept_names, uint64_t current_bit, std::vector<uint8_t>& bytes);
		void Execute(std::vector<uint8_t>& wasm);
		void FuzzTest();
	}

	namespace Export {
		void GenerateQRCode(uint64_t size, std::vector<uint8_t>& bytes, int width, int height, std::string path);
	}

	namespace Import {
		void ScanQRCode(std::vector<uint8_t>& bytes, std::string path);
	}
}