#include "plugin.h"

typedef struct _DBG_LIST_ENTRY
{
    struct _DBG_LIST_ENTRY *Flink;
    struct _DBG_LIST_ENTRY *Blink;
} DBG_LIST_ENTRY, *PDBG_LIST_ENTRY;

typedef struct _DBG_LDRP_DLL_NOTIFICATION_BLOCK
{
    DBG_LIST_ENTRY Links;
    duint NotificationFunction;
    duint Context;
} DBG_LDRP_DLL_NOTIFICATION_BLOCK, *PDBG_LDRP_DLL_NOTIFICATION_BLOCK;

static bool
cbViewDllNotification(int argc, char **argv)
{
    static duint addr_LdrpDllNotificationList = 0;

#ifdef _WIN64
    auto symbol = "LdrpDllNotificationList";
#else
    auto symbol = "_LdrpDllNotificationList";
#endif
    if (addr_LdrpDllNotificationList == 0)
    {
        addr_LdrpDllNotificationList = DbgValFromString(symbol);
        if (addr_LdrpDllNotificationList == 0)
        {
            _plugin_logputs(
                "[" PLUGIN_NAME
                "] Failed to get LdrpDllNotificationList! You need to ensure that the symbols are loaded successfully!");
            return false;
        }
    }

    duint next = 0;
    if (!DbgMemRead(addr_LdrpDllNotificationList, (unsigned char *)&next, sizeof(next)))
    {
        return false;
    }

    while (next != addr_LdrpDllNotificationList)
    {
        DBG_LDRP_DLL_NOTIFICATION_BLOCK st = {0};
        duint readsize = 16;
#ifdef _WIN64
        readsize = 32;
#endif
        if (!DbgMemRead(next, (unsigned char *)&st, readsize))
        {
            return false;
        }

        _plugin_logprintf(
            "[" PLUGIN_NAME "] NotificationFunction:%p Flink:%p Blink:%p Context:%p\n",
            st.NotificationFunction,
            st.Links.Flink,
            st.Links.Blink,
            st.Context);

        if (!DbgMemRead(next, (unsigned char *)&next, sizeof(next)))
        {
            return false;
        }
    }

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
