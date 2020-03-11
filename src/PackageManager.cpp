/*
  transactional-update - apply updates to the system in an atomic way

  Copyright (c) 2016 - 2020 SUSE LLC

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "PackageManager.h"
#include "Packages/Zypper.h"
using namespace std;

unique_ptr<PackageManager> PackageManagerFactory::create() {
    if (filesystem::exists("/usr/bin/zypper")) {
        return make_unique<Zypper>();
    } else {
        throw runtime_error{"No supported package manager found."};
    }
}
