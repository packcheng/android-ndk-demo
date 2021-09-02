package com.packcheng.ndkdemo.t4;

/**
 * @author packcheng <a href="mailto:packcheng_jo@outlook.com">Contact me.</a>
 * @since 2021/9/2 21:43
 */
class DParcel {
    private long mNativePtr; // used by native code

    private DParcel(long nativePtr) {
        init(nativePtr);
    }

    private void init(long nativePtr) {
        if (nativePtr != 0) {
            mNativePtr = nativePtr;
        } else {
            mNativePtr = nativeCreate();
        }
    }

    private static class Holder {
        private static DParcel instance = new DParcel(0);
    }

    public static DParcel obtain() {
        return Holder.instance;
    }

    public final void setDataPosition(int pos) {
        nativeSetDataPosition(mNativePtr, pos);
    }

    public final void writeInt(int val) {
        nativeWriteInt(mNativePtr, val);
    }

    public final int readInt() {
        return nativeReadInt(mNativePtr);
    }

    private static native long nativeCreate();

    private static native void nativeSetDataPosition(long nativePtr, int pos);

    private static native void nativeWriteInt(long nativePtr, int val);

    private static native int nativeReadInt(long nativePtr);
}
