# X64DBG-ViewDllNotification

X64DBG plugin viewing dll notification

![image](https://user-images.githubusercontent.com/13917777/178156979-11bd4ade-3031-40c0-bb85-0606fba90d5c.png)


## Usage
```
ViewDllNotification
```

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

