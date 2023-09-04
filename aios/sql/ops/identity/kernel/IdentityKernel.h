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

#include <memory>
#include <stdint.h>
#include <string>

#include "navi/common.h"
#include "navi/engine/Kernel.h"
#include "navi/engine/KernelConfigContext.h"
#include "sql/common/Log.h" // IWYU pragma: keep
#include "sql/proto/SqlSearchInfo.pb.h"
#include "sql/proto/SqlSearchInfoCollectorR.h"
#include "sql/resource/QueryMetricReporterR.h"

namespace autil {
class ScopedTime2;
} // namespace autil

namespace navi {
class KernelComputeContext;
class KernelDefBuilder;
class KernelInitContext;
} // namespace navi

namespace sql {

class IdentityKernel : public navi::Kernel {
public:
    IdentityKernel();
    ~IdentityKernel();

public:
    void def(navi::KernelDefBuilder &builder) const override;
    bool config(navi::KernelConfigContext &ctx) override;
    navi::ErrorCode init(navi::KernelInitContext &initContext) override;
    navi::ErrorCode compute(navi::KernelComputeContext &runContext) override;

private:
    void reportMetrics();

private:
    KERNEL_DEPEND_DECLARE();

private:
    KERNEL_DEPEND_ON(QueryMetricReporterR, _queryMetricReporterR);
    KERNEL_DEPEND_ON(SqlSearchInfoCollectorR, _sqlSearchInfoCollectorR);
    std::string _scope;
    int32_t _opId;
    std::unique_ptr<autil::ScopedTime2> _durationTimer;
    IdentityInfo _identityInfo;
};

typedef std::shared_ptr<IdentityKernel> IdentityKernelPtr;
} // namespace sql
