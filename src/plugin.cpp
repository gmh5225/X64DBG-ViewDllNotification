#include "plugin.h"

static bool
cbViewDllNotification(int argc, char **argv)
{
    return true;
}

// Initialize your plugin data here.
bool
pluginInit(PLUG_INITSTRUCT *initStruct)
{
    if (!_plugin_registercommand(pluginHandle, "ViewDllNotification", cbViewDllNotification, true))
    {
        _plugin_logputs("[" PLUGIN_NAME "] Error registering the ViewDllNotification command!");
    }

    return true; // Return false to cancel loading the plugin.
}

// Deinitialize your plugin data here.
void
pluginStop()
{
}

// Do GUI/Menu related things here.
void
pluginSetup()
{
}
