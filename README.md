# DLL Injection Sample Payload

Recently I've been practicing DLL injection, but I had a hard time finding a ready-to-use, out-of-the-box payload—either they're not available, or they are hosted on shady websites.
So, I made a simple payload to verify whether the injector is working correctly or not. This is also a rare opportunity for me to practice my rusty C skills.

# What does it do

It outputs a message when `DLL_PROCESS_ATTACH` or `DLL_PROCESS_DETACH` is triggered.
Nothing will happen on `DLL_THREAD_ATTACH` or `DLL_THREAD_DETACH`.

# Differences Between Each Version

Usually, the injector, the payload, and the target process all need to have the same architecture (x86, x64).

#### (Recommended) DllInjectionSamplePayload_x86.dll & DllInjectionSamplePayload_x64.dll

Uses `OutputDebugStringW`.

The messages can be captured with [DebugView](https://learn.microsoft.com/en-us/sysinternals/downloads/debugview).

#### DllInjectionSamplePayload_Msgbox_x86.dll & DllInjectionSamplePayload_Msgbox_x64.dll

Uses `MessageBoxW` and `MessageBoxTimeoutW`.
The message is displayed for 5 seconds when `DLL_PROCESS_DETACH` occurs.

***Warning***
***Use Msgbox payloads with caution. Both calling user32 functions and using blocking functions are discouraged by Microsoft. Though it's way more obvious than `OutputDebugStringW` and won't always cause deadlock.***

# Build it Yourself Tips

The `MSGBOX` macro determines whether it uses message box or not.
The default is off.

# Extra Materials

* DebugView (Sysinternals): https://learn.microsoft.com/en-us/sysinternals/downloads/debugview
* Dynamic-Link Library Best Practices (Microsoft Learn): https://learn.microsoft.com/windows/win32/dlls/dynamic-link-library-best-practices
* DLL's Loader Lock Problem (Stack Overflow): https://stackoverflow.com/questions/13874324/what-is-a-loader-lock