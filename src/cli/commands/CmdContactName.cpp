/************************************************************
 *
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  EMAIL:
 *  fellowtraveler@opentransactions.org
 *
 *  WEBSITE:
 *  http://www.opentransactions.org/
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This Source Code Form is subject to the terms of the
 *   Mozilla Public License, v. 2.0. If a copy of the MPL
 *   was not distributed with this file, You can obtain one
 *   at http://mozilla.org/MPL/2.0/.
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will
 *   be useful, but WITHOUT ANY WARRANTY; without even the
 *   implied warranty of MERCHANTABILITY or FITNESS FOR A
 *   PARTICULAR PURPOSE.  See the Mozilla Public License
 *   for more details.
 *
 ************************************************************/

#include "CmdContactName.hpp"

#include <opentxs/core/Version.hpp>

#include <opentxs/api/Api.hpp>
#include <opentxs/api/ContactManager.hpp>
#include <opentxs/api/OT.hpp>
#include <opentxs/client/OTME_too.hpp>
#include <opentxs/contact/Contact.hpp>
#include <opentxs/contact/ContactData.hpp>
#include <opentxs/core/Identifier.hpp>
#include <opentxs/core/Log.hpp>
#include <opentxs/core/String.hpp>

namespace opentxs
{
CmdContactName::CmdContactName()
{
    command = "contactname";
    args[0] = "--contact <nym>";
    category = catOtherUsers;
    help = "Retrieve the label for a contact";
}

std::int32_t CmdContactName::runWithOptions()
{
    return run(getOption("contact"));
}

std::int32_t CmdContactName::run(const std::string& id)
{
    if (id.empty()) {

        return -1;
    }

    const auto contact =
        OT::App().Contact().Contact(Identifier(String(id.c_str())));

    if (false == bool(contact)) {

        return -1;
    }

    otOut << contact->Label() << std::endl;

    return 0;
}
} // namespace opentxs