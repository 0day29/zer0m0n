zer0m0n v0.9 (DEVELOPMENT BRANCH)
=================================

To-do :
+ NtCreateThreadEx x64
+ Use cuckoomon syscalls logs
+ Dynamic-static analysis integration
+ Standalone (procmon-like) version :]
+ Use inverted IRP calls with kernel buffer instead of filter comm. ports :]
+ fix random socket desynch
+ code cleaning

v0.9 changes :
+ cuckoo 1.2 compatibility
+ no need ActivePython anymore

v0.8 changes :
+ Dump a physical page of memory when an unknown region of code is executed. (x86-32 only)

v0.7 changes :
+ x64 driver version !!

v0.6 changes :
+ handle files deletion (through NtDeleteFile, NtCreateFile/NtClose via FILE_DELETE_ON_CLOSE and NtSetInformationFile)
+ cuckoo 1.1 compatibility

v0.5 changes :
+ bug fixes
+ win7 support
+ NtCreateUserProcess() hook 
+ NtUserCallNoParam() hook 
+ NtCreateThreadEx() hook 

v0.4 changes :
+ more anti VM detection features
+ log new loaded modules through NtCreateSection hook 
+ handle shutdown attempt through ExitWindowsEx() in hooking NtUserCallOneParam() (shadow ssdt) => abort analysis

v0.3 changes :
+ fix minor bugs
+ fix NtTerminateProcess() race condition (notify analyzer.py of process termination)
+ fix hook NtDelayExecution() => log the call before executing it
+ Signatures :]
+ some anti VM (virtualbox) detection features (based on pafish PoC)
+ NtReadVirtualMemory() hook
+ NtResumeThread() hook
+ handle driver execution (abort analysis)

v0.2 changes :
+ NtDeviceIoControlFile() hook
+ NtCreateMutant() hook
+ NtDelayExecution() hook
+ NtTerminateProcess() hook
+ Fixed deadlock issue (FltSendMessage infinite wait switched to 100ms timeout)
+ Fixed performance issues (drop) using userland app multithreading
