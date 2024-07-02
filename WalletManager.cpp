#include "WalletManager.hpp"

/** Add wallet for new user */
void WalletManager::addWallet(const std::string &user)
{
    if (wallets.find(user) != wallets.end())
    {
        throw std::invalid_argument("Wallet for user already exist");
    }
    wallets[user] = Wallet{};
}

/** Get the wallet for the user */
Wallet &WalletManager::gerUserWallet(const std::string &user)
{
    return wallets[user];
}

void WalletManager::printWallets() const
{
    std::cout << "-----------------------------------" << std::endl;

    for (auto &[user, wallet] : wallets)
    {
        std::cout << "User : " << user << std::endl;
        wallet.printWallet();
        std::cout << "-----------------------------------" << std::endl;
    }
}