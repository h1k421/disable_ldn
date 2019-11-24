
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <malloc.h>

#include <switch.h>
#include <stratosphere.hpp>

#include "iuserservicecreator.hpp"

extern "C" {
    extern u32 __start__;

    u32 __nx_applet_type = AppletType_None;

    #define INNER_HEAP_SIZE 0x60000
    size_t nx_inner_heap_size = INNER_HEAP_SIZE;
    char   nx_inner_heap[INNER_HEAP_SIZE];
    
    void __libnx_initheap(void);
    void __appInit(void);
    void __appExit(void);
}


void __libnx_initheap(void) {
    void*  addr = nx_inner_heap;
    size_t size = nx_inner_heap_size;

    /* Newlib */
    extern char* fake_heap_start;
    extern char* fake_heap_end;

    fake_heap_start = (char*)addr;
    fake_heap_end   = (char*)addr + size;
}

void __appInit(void) {
    svcSleepThread(10000000000L);

    SetFirmwareVersionForLibnx();

    Result rc = smInitialize();
    if (R_FAILED(rc)) {
        fatalSimple(MAKERESULT(Module_Libnx, LibnxError_InitFail_SM));
    }
}

void __appExit(void) {
    smExit();
}

struct LdnMitmManagerOptions {
    static const size_t PointerBufferSize = 0x1000;
    static const size_t MaxDomains = 0x10;
    static const size_t MaxDomainObjects = 0x100;
};

using LdnMitmManager = WaitableManager<LdnMitmManagerOptions>;

int main(int argc, char **argv)
{
    auto server_manager = new LdnMitmManager(2);

    /* Create ldn:u mitm. */
    AddMitmServerToManager<IUserServiceCreator>(server_manager, "ldn:u", 3);

    /* Loop forever, servicing our services. */
    server_manager->Process();

    return 0;
}
