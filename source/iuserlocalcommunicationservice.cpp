#include "iuserlocalcommunicationservice.hpp"

static constexpr u32 Module_Ldn = 203;

static constexpr Result ResultLdnDeviceDisabled  = MAKERESULT(Module_Ldn, 22);

Result IUserLocalCommunicationService::InitializeOld(u64 unk, PidDescriptor pid) {
    return ResultLdnDeviceDisabled;
}

Result IUserLocalCommunicationService::Initialize(u64 unk, PidDescriptor pid) {
    return ResultLdnDeviceDisabled;
}
