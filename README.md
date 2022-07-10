# X64DBG-ViewDllNotification

![image](https://user-images.githubusercontent.com/13917777/178156916-cde705de-fc79-4101-bf68-a0c936fec4b4.png)

## Building

From a Visual Studio command prompt:

```
cmake -B build64 -A x64
cmake --build build64 --config Release
```

You will get `build64\ViewDllNotification.sln` that you can open in Visual Studio.

To build a 32-bit plugin:

```
cmake -B build32 -A Win32
cmake --build build32 --config Release
```

Alternatively you can open this folder in Visual Studio/CLion/Qt Creator.

