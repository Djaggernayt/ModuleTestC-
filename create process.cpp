#include "process_creation.h"

bool ProcessCreation::createProcess(const std::string& commandLine) {
    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    // Создание процесса
    if (!CreateProcessA(
        nullptr,                   // Имя модуля (используем командную строку)
        const_cast<LPSTR>(commandLine.c_str()), // Командная строка
        nullptr,                   // Атрибуты процесса
        nullptr,                   // Атрибуты потока
        FALSE,                     // Наследование дескрипторов
        0,                         // Флаги создания
        nullptr,                   // Окружение
        nullptr,                   // Текущий каталог
        &si,                       // STARTUPINFO
        &pi                        // PROCESS_INFORMATION
    )) {
        throw std::runtime_error("Failed to create process.");
    }

    // Закрываем ненужные дескрипторы
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);

    return true;
}

bool ProcessCreation::isProcessRunning(HANDLE processHandle) {
    DWORD exitCode;
    if (GetExitCodeProcess(processHandle, &exitCode)) {
        return exitCode == STILL_ACTIVE;
    }
    return false;
}

void ProcessCreation::closeProcessHandle(HANDLE processHandle) {
    CloseHandle(processHandle);
}