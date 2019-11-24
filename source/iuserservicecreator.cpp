#include "iuserservicecreator.hpp"

Result IUserServiceCreator::CreateUserLocalCommunicationService(Out<std::shared_ptr<IUserLocalCommunicationService>> out) {
    out.SetValue(std::move(std::make_shared<IUserLocalCommunicationService>()));

    return 0;
}
