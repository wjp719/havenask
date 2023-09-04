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
#pragma once

#include <stddef.h>
#include <stdint.h>
#include <string>
#include <unordered_map>

#include "autil/Log.h"
#include "autil/Span.h"
#include "swift/common/Common.h"
#include "swift/common/FieldGroupReader.h"
#include "swift/common/FieldGroupWriter.h"
#include "swift/filter/HashUtil.h" // IWYU pragma: keep

namespace swift {} // namespace swift

namespace swift {
namespace filter {
class EliminateFieldFilter {
public:
    typedef std::unordered_map<autil::StringView, size_t, SimpleHash> RequiredFieldMap;

public:
    EliminateFieldFilter();
    ~EliminateFieldFilter();

private:
    EliminateFieldFilter(const EliminateFieldFilter &);
    EliminateFieldFilter &operator=(const EliminateFieldFilter &);

public:
    void addRequiredField(const autil::StringView &fieldName, size_t offset);

    bool filterFields(const common::FieldGroupReader &fieldGroupReader, common::FieldGroupWriter &fieldGroupWriter);

    bool getFilteredFields(const std::string &productionData, std::string &consumptionData);

private:
    RequiredFieldMap _requiredFieldMap;
    int32_t _maxFieldOffset;
    common::FieldGroupReader _fieldGroupReader;
    common::FieldGroupWriter _fieldGroupWriter;

private:
    AUTIL_LOG_DECLARE();
};

SWIFT_TYPEDEF_PTR(EliminateFieldFilter);

} // namespace filter
} // namespace swift
