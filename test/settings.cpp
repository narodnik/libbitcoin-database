/**
 * Copyright (c) 2011-2017 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <boost/test/unit_test.hpp>

#include <bitcoin/database.hpp>

using namespace bc;

BOOST_AUTO_TEST_SUITE(settings_tests)

// constructors
//-----------------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(settings__construct__default_context__expected)
{
    database::settings configuration;
    BOOST_REQUIRE_EQUAL(configuration.directory, "blockchain");
    BOOST_REQUIRE(configuration.index_addresses);
    BOOST_REQUIRE(!configuration.flush_writes);
    BOOST_REQUIRE_EQUAL(configuration.file_growth_rate, 5u);
    BOOST_REQUIRE_EQUAL(configuration.block_table_buckets, 0u);
    BOOST_REQUIRE_EQUAL(configuration.transaction_table_buckets, 0u);
    BOOST_REQUIRE_EQUAL(configuration.address_table_buckets, 0u);
    BOOST_REQUIRE_EQUAL(configuration.cache_capacity, 0u);
}

BOOST_AUTO_TEST_CASE(settings__construct__none_context__expected)
{
    database::settings configuration(config::settings::none);
    BOOST_REQUIRE_EQUAL(configuration.directory, "blockchain");
    BOOST_REQUIRE(configuration.index_addresses);
    BOOST_REQUIRE(!configuration.flush_writes);
    BOOST_REQUIRE_EQUAL(configuration.file_growth_rate, 5u);
    BOOST_REQUIRE_EQUAL(configuration.block_table_buckets, 0u);
    BOOST_REQUIRE_EQUAL(configuration.transaction_table_buckets, 0u);
    BOOST_REQUIRE_EQUAL(configuration.address_table_buckets, 0u);
    BOOST_REQUIRE_EQUAL(configuration.cache_capacity, 0u);
}

BOOST_AUTO_TEST_CASE(settings__construct__mainnet_context__expected)
{
    database::settings configuration(config::settings::mainnet);
    BOOST_REQUIRE_EQUAL(configuration.directory, "blockchain");
    BOOST_REQUIRE(configuration.index_addresses);
    BOOST_REQUIRE(!configuration.flush_writes);
    BOOST_REQUIRE_EQUAL(configuration.file_growth_rate, 5u);
    BOOST_REQUIRE_EQUAL(configuration.block_table_buckets, 650000u);
    BOOST_REQUIRE_EQUAL(configuration.transaction_table_buckets, 110000000u);
    BOOST_REQUIRE_EQUAL(configuration.address_table_buckets, 107000000u);
    BOOST_REQUIRE_EQUAL(configuration.cache_capacity, 0u);
}

BOOST_AUTO_TEST_CASE(settings__construct__testnet_context__expected)
{
    database::settings configuration(config::settings::testnet);
    BOOST_REQUIRE_EQUAL(configuration.directory, "blockchain");
    BOOST_REQUIRE(configuration.index_addresses);
    BOOST_REQUIRE(!configuration.flush_writes);
    BOOST_REQUIRE_EQUAL(configuration.file_growth_rate, 5u);
    BOOST_REQUIRE_EQUAL(configuration.block_table_buckets, 650000u);
    BOOST_REQUIRE_EQUAL(configuration.transaction_table_buckets, 110000000u);
    BOOST_REQUIRE_EQUAL(configuration.address_table_buckets, 107000000u);
    BOOST_REQUIRE_EQUAL(configuration.cache_capacity, 0u);
}

BOOST_AUTO_TEST_SUITE_END()
