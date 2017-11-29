/**
 * Kinesis Video MKV generator statics
 */
#define LOG_CLASS "MkvGeneratorStatics"
#include "Include_i.h"

/**
 * Static definitions
 */
BYTE gMkvHeaderBits[] = {
        0x1A, 0x45, 0xDF, 0xA3, // EBML element id
        0xA4, // Size of the header
        0x42, 0x86, 0x81, 0x01, // EBML version
        0x42, 0xF7, 0x81, 0x01, // EBML read version
        0x42, 0xF2, 0x81, 0x04, // EBML max id len
        0x42, 0xF3, 0x81, 0x08, // EBML max size len
        0x42, 0x82, 0x89, 0x6D, 0x61, 0x74, 0x72, 0x6F, 0x73, 0x6B, 0x61, 0x00, // Doc type - "matroska"
        0x42, 0x87, 0x81, 0x02, // Doc type version - 2
        0x42, 0x85, 0x81, 0x02, // Doc type read version - 2
};
UINT32 gMkvHeaderBitsSize = SIZEOF(gMkvHeaderBits);

BYTE gMkvSegmentHeaderBits[] = {
        0x18, 0x53, 0x80, 0x67, // Segment header id
        0xFF, // Size of the header - unknown
};
UINT32 gMkvSegmentHeaderBitsSize = SIZEOF(gMkvSegmentHeaderBits);

BYTE gMkvSegmentInfoBits[] = {
        0x15, 0x49, 0xA9, 0x66, // Segment info id
        0xDE, // Size of the header
        0x73, 0xA4, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // SegmentUID
        0x2A, 0xD7, 0xB1, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // TimecodeScale - Placeholder to fix-up the timecode scale
        0x7B, 0xA9, 0x92, 0x4B, 0x69, 0x6E, 0x65, 0x73, 0x69, 0x73, 0x20, 0x56, 0x69, 0x64, 0x65, 0x6F, 0x20, 0x53, 0x44, 0x4B, 0x00, // Title - "Kinesis Video SDK"
        0x4D, 0x80, 0x92, 0x4B, 0x69, 0x6E, 0x65, 0x73, 0x69, 0x73, 0x20, 0x56, 0x69, 0x64, 0x65, 0x6F, 0x20, 0x53, 0x44, 0x4B, 0x00, // Muxing app - "Kinesis Video SDK"
        0x57, 0x41, 0x92, 0x4B, 0x69, 0x6E, 0x65, 0x73, 0x69, 0x73, 0x20, 0x56, 0x69, 0x64, 0x65, 0x6F, 0x20, 0x53, 0x44, 0x4B, 0x00, // Writing app - "Kinesis Video SDK"
};
UINT32 gMkvSegmentInfoBitsSize = SIZEOF(gMkvSegmentInfoBits);

BYTE gMkvTrackInfoBits[] = {
        0x16, 0x54, 0xAE, 0x6B, // Tracks
        0x10, 0x00, 0x00, 0x5B, // Size of the header - 4 bytes wide to accommodate max codec private data
        0xAE, // Track entry
        0x10, 0x00, 0x00, 0x56, // Size of the track - 4 bytes wide to accommodate max codec private data
        0xD7, 0x81, 0x01, // Track number
        0x73, 0xC5, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Track ID - placeholder for 8 bytes
        0x83, 0x81, 0x01, // Track type
        0x53, 0x6E,
        0xA0,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Name - placeholder for 16 chars
        0x86,
        0xA0,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Codec ID - placeholder for 16 chars
};
UINT32 gMkvTrackInfoBitsSize = SIZEOF(gMkvTrackInfoBits);

BYTE gMkvCodecPrivateDataElem[] = {
        0x63, 0xA2, // CodecPrivate
};
UINT32 gMkvCodecPrivateDataElemSize = SIZEOF(gMkvCodecPrivateDataElem);

BYTE gMkvTrackVideoBits[] = {
        0xE0, // Track Video Element
        0x10, 0x00, 0x00, 0x08, // Size of the Video element - 4 bytes wide to accommodate future extension
        0xB0, // Pixel width
        0x82, // 2-byte size
        0x00, 0x00,
        0xBA, // Pixel height
        0x82, // 2-byte size
        0x00, 0x00,
};
UINT32 gMkvTrackVideoBitsSize = SIZEOF(gMkvTrackVideoBits);

BYTE gMkvClusterInfoBits[] = {
        0x1F, 0x43, 0xB6, 0x75, // Cluster
        0xFF, // Size of the header - unknown
        0xE7, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Time code - a placeholder
        0xA7, 0x81, 0x00, // Position - 0 for live
};
UINT32 gMkvClusterInfoBitsSize = SIZEOF(gMkvClusterInfoBits);

BYTE gMkvSimpleBlockBits[] = {
        0xA3, // SimpleBlock
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Size of the block - needs to be fixed up
        0x81, // Track number
        0x00, 0x00, // Timecode - relative to cluster timecode - INT16 - needs to be fixed up
        0x00, // Flags - needs to be fixed up
        // Frame data follows
};
UINT32 gMkvSimpleBlockBitsSize = SIZEOF(gMkvSimpleBlockBits);
