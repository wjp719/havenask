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

#include "indexlib/index/ann/aitheta2/CommonDefine.h"
#include "indexlib/index/ann/aitheta2/impl/SegmentMeta.h"
#include "indexlib/index/ann/aitheta2/util/segment_data/SegmentDataReader.h"
#include "indexlib/index/ann/aitheta2/util/segment_data/SegmentDataWriter.h"
namespace indexlibv2::index::ann {

class Segment
{
public:
    Segment(const AithetaIndexConfig& config, SegmentType type, bool isOnline)
        : _indexConfig(config)
        , _isOnline(isOnline)
    {
        _segmentMeta.SetDimension(_indexConfig.dimension);
        _segmentMeta.SetSegmentType(type);
    }
    Segment() = default;
    virtual ~Segment() = default;

public:
    virtual bool Close();

public:
    void SetIndexConfig(const AithetaIndexConfig& config) { _indexConfig = config; }
    void SetDirectory(const indexlib::file_system::DirectoryPtr& dir) { _directory = dir; }
    void SetMergedSegment() { _segmentMeta.SetMergedSegment(); }
    const indexlib::file_system::DirectoryPtr& GetDirectory() const { return _directory; }
    const SegmentMeta& GetSegmentMeta() const { return _segmentMeta; }
    bool AddIndexMeta(index_id_t id, const IndexMeta& meta) { return _segmentMeta.AddIndexMeta(id, meta); }

public:
    SegmentDataWriterPtr GetSegmentDataWriter();
    SegmentDataReaderPtr GetSegmentDataReader();

protected:
    AithetaIndexConfig _indexConfig {};
    SegmentMeta _segmentMeta {};
    bool _isOnline = false;
    indexlib::file_system::DirectoryPtr _directory {};
    SegmentDataWriterPtr _segmentDataWriter {};
    SegmentDataReaderPtr _segmentDataReader {};
    AUTIL_LOG_DECLARE();
};

typedef std::shared_ptr<Segment> SegmentPtr;
} // namespace indexlibv2::index::ann
