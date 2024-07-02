#pragma once

#include "Wallet.hpp"

class WalletManager
{
public:
    WalletManager() = default;

    /** Add wallet for new user */
    void addWallet(const std::string &user);

    /** Get the wallet for the user */
    Wallet &gerUserWallet(const std::string &user);
    /** Prints all available wallets */
    void printWallets() const;

private:
    std::unordered_map<std::string, Wallet> wallets;
};