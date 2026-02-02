#include "file_operations.h"
#include <filesystem> // Для работы с файловой системой

void FileOperations::writeToFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for writing.");
    }
    file << content;
    file.close();
}

std::string FileOperations::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for reading.");
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

void FileOperations::deleteFile(const std::string& filename) {
    if (!std::filesystem::remove(filename)) {
        throw std::runtime_error("Failed to delete file.");
    }
}

bool FileOperations::fileExists(const std::string& filename) {
    return std::filesystem::exists(filename);
}