/*
 * Copyright 2014-present Alibaba Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "swift/client/fake_client/FakeSwiftAdminAdapter.h"

#include "swift/protocol/ErrCode.pb.h"

namespace swift {
namespace client {
AUTIL_LOG_SETUP(swift, FakeSwiftAdminAdapter);

FakeSwiftAdminAdapter::FakeSwiftAdminAdapter()
    : network::SwiftAdminAdapter("", network::SwiftRpcChannelManagerPtr())
    , _partCount(1)
    , _errorCode(protocol::ERROR_NONE)
    , _needSchema(false)
    , _schemaRetVersion(0)
    , _topicType(protocol::TOPIC_TYPE_NORMAL)
    , _sealed(false)
    , _callCnt(0)
    , _hasPermission(false) {}

FakeSwiftAdminAdapter::~FakeSwiftAdminAdapter() {}

} // namespace client
} // namespace swift
