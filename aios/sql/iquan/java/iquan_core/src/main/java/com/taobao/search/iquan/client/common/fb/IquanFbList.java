// automatically generated by the FlatBuffers compiler, do not modify

package com.taobao.search.iquan.client.common.fb;

import java.nio.*;
import java.lang.*;
import java.util.*;
import com.google.flatbuffers.*;

@SuppressWarnings("unused")
public final class IquanFbList extends Table {
  public static IquanFbList getRootAsIquanFbList(ByteBuffer _bb) { return getRootAsIquanFbList(_bb, new IquanFbList()); }
  public static IquanFbList getRootAsIquanFbList(ByteBuffer _bb, IquanFbList obj) { _bb.order(ByteOrder.LITTLE_ENDIAN); return (obj.__assign(_bb.getInt(_bb.position()) + _bb.position(), _bb)); }
  public void __init(int _i, ByteBuffer _bb) { bb_pos = _i; bb = _bb; }
  public IquanFbList __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public IquanFbAny value(int j) { return value(new IquanFbAny(), j); }
  public IquanFbAny value(IquanFbAny obj, int j) { int o = __offset(4); return o != 0 ? obj.__assign(__indirect(__vector(o) + j * 4), bb) : null; }
  public int valueLength() { int o = __offset(4); return o != 0 ? __vector_len(o) : 0; }

  public static int createIquanFbList(FlatBufferBuilder builder,
      int valueOffset) {
    builder.startObject(1);
    IquanFbList.addValue(builder, valueOffset);
    return IquanFbList.endIquanFbList(builder);
  }

  public static void startIquanFbList(FlatBufferBuilder builder) { builder.startObject(1); }
  public static void addValue(FlatBufferBuilder builder, int valueOffset) { builder.addOffset(0, valueOffset, 0); }
  public static int createValueVector(FlatBufferBuilder builder, int[] data) { builder.startVector(4, data.length, 4); for (int i = data.length - 1; i >= 0; i--) builder.addOffset(data[i]); return builder.endVector(); }
  public static void startValueVector(FlatBufferBuilder builder, int numElems) { builder.startVector(4, numElems, 4); }
  public static int endIquanFbList(FlatBufferBuilder builder) {
    int o = builder.endObject();
    return o;
  }
}

