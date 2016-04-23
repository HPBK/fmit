// Copyright 2004 "Gilles Degottex"

// This file is part of "fmit"

// "fmit" is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// "fmit" is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#include "GLErrorHistory.h"

static const unsigned char g_icon_error_graph[] = {
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
    0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20,
    0x08, 0x06, 0x00, 0x00, 0x00, 0x73, 0x7a, 0x7a, 0xf4, 0x00, 0x00, 0x06,
    0xa7, 0x49, 0x44, 0x41, 0x54, 0x78, 0x9c, 0xad, 0x96, 0x6b, 0x6c, 0x14,
    0xe7, 0x15, 0x86, 0x9f, 0x99, 0xd9, 0x9d, 0xdd, 0xf1, 0xda, 0x2c, 0xbe,
    0xc6, 0x18, 0x63, 0x9b, 0xa4, 0x4d, 0x7c, 0x81, 0x60, 0x70, 0x1a, 0x1b,
    0x5a, 0xe3, 0xc4, 0x24, 0xa4, 0xa2, 0x11, 0x25, 0x40, 0x12, 0x88, 0x94,
    0x0b, 0xa9, 0x22, 0x15, 0xa5, 0x37, 0x45, 0x95, 0xaa, 0x26, 0x52, 0x2a,
    0x35, 0x45, 0x55, 0xd3, 0x4a, 0xa1, 0x6d, 0x54, 0x1a, 0xa9, 0x09, 0x71,
    0x83, 0x52, 0xe4, 0x34, 0x8d, 0x9a, 0x90, 0xd0, 0x48, 0x34, 0xa9, 0xb9,
    0xd8, 0x01, 0x92, 0x62, 0xa8, 0xb9, 0x18, 0xb1, 0x06, 0xdb, 0x05, 0x7b,
    0xd7, 0x7b, 0xf1, 0xee, 0xec, 0xce, 0xee, 0xec, 0xee, 0xcc, 0xf4, 0x87,
    0xed, 0x05, 0x5f, 0xb0, 0x37, 0xd0, 0xf7, 0xdf, 0x9c, 0xf9, 0xbe, 0xf3,
    0x3e, 0x73, 0xe6, 0x3b, 0x67, 0x06, 0xbe, 0xbc, 0x5c, 0xc0, 0x36, 0xa0,
    0x43, 0x90, 0x65, 0x43, 0x94, 0xe5, 0xa4, 0x20, 0x49, 0x1a, 0xa0, 0x02,
    0x67, 0x81, 0xe7, 0x80, 0x82, 0x6c, 0x93, 0x09, 0x5f, 0xd2, 0xfc, 0x6b,
    0x40, 0x7b, 0xcd, 0x13, 0x4f, 0x56, 0x55, 0xaf, 0x5b, 0x4f, 0x61, 0xe9,
    0x02, 0xf2, 0x9d, 0x06, 0x05, 0x8e, 0x34, 0x45, 0x4e, 0x0b, 0x77, 0xca,
    0x45, 0xe7, 0xfe, 0x7f, 0xf1, 0xfa, 0xcb, 0xbf, 0x4a, 0xa8, 0x81, 0xe0,
    0x5e, 0xe0, 0x79, 0x60, 0xe8, 0xff, 0x05, 0xf0, 0x03, 0xa5, 0xa8, 0xf8,
    0xd7, 0x6b, 0x7f, 0xfb, 0xaa, 0x5c, 0x52, 0x5e, 0x01, 0xc0, 0x7c, 0x47,
    0x3a, 0x63, 0xde, 0x50, 0xb4, 0x98, 0x65, 0x85, 0x95, 0xf4, 0x45, 0xbc,
    0x9c, 0x09, 0x0d, 0xb1, 0xe7, 0xbd, 0x7d, 0xbc, 0xf3, 0xdc, 0x8b, 0x17,
    0x80, 0x35, 0xc0, 0xc0, 0xcd, 0x00, 0xb8, 0x81, 0x37, 0x16, 0x36, 0xb7,
    0x6c, 0xbc, 0xf7, 0x85, 0x9f, 0xa1, 0x28, 0xca, 0xac, 0xe6, 0x1e, 0xd5,
    0x47, 0x5f, 0x64, 0x04, 0x35, 0x25, 0xf2, 0xf9, 0x17, 0xbd, 0xbc, 0xf3,
    0xcc, 0xb3, 0x03, 0x98, 0xe6, 0x1a, 0xe0, 0xc2, 0x8d, 0x00, 0x34, 0x00,
    0xed, 0x4d, 0x3f, 0x79, 0xfe, 0xd6, 0x87, 0xb7, 0x3c, 0x46, 0xb1, 0x53,
    0xc6, 0xb2, 0xc0, 0x69, 0x33, 0x71, 0xd9, 0x41, 0x92, 0x12, 0x94, 0x2a,
    0xf3, 0xb9, 0xb3, 0xb0, 0x62, 0x9a, 0x79, 0x34, 0x25, 0xa1, 0x26, 0x25,
    0x3c, 0x17, 0x06, 0xd8, 0xf7, 0xf4, 0xe3, 0x43, 0x96, 0x61, 0x54, 0x03,
    0x91, 0xa9, 0x06, 0xd2, 0x2c, 0xe6, 0xad, 0x39, 0xf9, 0xf9, 0x9f, 0x7c,
    0xf7, 0xf5, 0xdd, 0xc5, 0x77, 0x35, 0x36, 0xd2, 0xd9, 0x77, 0x81, 0xfd,
    0xbd, 0xe7, 0xe8, 0xea, 0xbf, 0xc4, 0xa1, 0x8b, 0xfd, 0x7c, 0xe2, 0xe9,
    0x27, 0x9e, 0x80, 0xa5, 0x45, 0x65, 0xa4, 0x2c, 0x9d, 0x8b, 0xaa, 0x0f,
    0xcf, 0x14, 0xf3, 0x68, 0x4a, 0xc4, 0x12, 0x20, 0x21, 0x8a, 0x79, 0xc1,
    0x53, 0x27, 0x83, 0x40, 0x67, 0xb6, 0x15, 0xa8, 0x05, 0x3a, 0x1f, 0xf8,
    0xc5, 0x0e, 0x77, 0xb4, 0xac, 0x8c, 0x68, 0x32, 0x49, 0x5a, 0x55, 0x89,
    0x75, 0x9f, 0xc2, 0x8a, 0x69, 0x98, 0x9a, 0x86, 0x63, 0x71, 0x25, 0xca,
    0x92, 0x3a, 0x44, 0xbb, 0x9d, 0x62, 0x45, 0xe1, 0xd1, 0xea, 0x0a, 0xc2,
    0x76, 0x83, 0xb0, 0x61, 0xcb, 0x98, 0xab, 0xe1, 0x51, 0xd4, 0x48, 0x98,
    0x50, 0xc0, 0x4f, 0xd7, 0x8f, 0xbe, 0x7f, 0x19, 0x58, 0x0c, 0xa4, 0xb2,
    0xa9, 0xc0, 0xde, 0x82, 0xe6, 0xe6, 0x1a, 0xa9, 0xa9, 0x89, 0x78, 0x2c,
    0x46, 0xe8, 0xc3, 0x7f, 0xe0, 0xfa, 0xfc, 0x2c, 0x1b, 0x97, 0xad, 0xa5,
    0xb1, 0xe2, 0x4e, 0x56, 0xd7, 0x34, 0x92, 0x3b, 0x12, 0xe7, 0xd2, 0x81,
    0xfd, 0xa8, 0x97, 0x2e, 0x62, 0xdc, 0x5a, 0x45, 0xb7, 0x2f, 0x44, 0xa9,
    0x6e, 0x92, 0xb0, 0xe7, 0xa0, 0x9a, 0xf6, 0x8c, 0xb9, 0x1a, 0x09, 0xa3,
    0x45, 0x55, 0xd2, 0x02, 0xf3, 0xb4, 0xbe, 0x3e, 0x0f, 0x70, 0x72, 0x2e,
    0x80, 0x66, 0xb9, 0xa8, 0xf8, 0xe7, 0x55, 0xdb, 0xb7, 0x23, 0x88, 0x22,
    0xe1, 0xdd, 0x7b, 0xd8, 0xd6, 0xb2, 0x95, 0xef, 0x3c, 0xb1, 0x9d, 0x15,
    0x2b, 0x6a, 0x39, 0x7a, 0xf4, 0x63, 0x62, 0xb1, 0x00, 0x0f, 0x7e, 0xeb,
    0x51, 0x9a, 0xef, 0xbe, 0x8f, 0x5c, 0x4d, 0xe2, 0x8b, 0xf7, 0xdf, 0xc6,
    0x56, 0x57, 0xcd, 0x25, 0x3d, 0x85, 0xe3, 0xca, 0x30, 0xba, 0xcd, 0x8e,
    0x1a, 0x8b, 0xa2, 0x46, 0xc2, 0x44, 0xc7, 0x41, 0x8c, 0xbc, 0x3c, 0xa2,
    0xc7, 0x8f, 0xbb, 0x81, 0xb6, 0x6b, 0xcd, 0x6c, 0x33, 0x00, 0x7c, 0xbb,
    0x60, 0xd5, 0x4a, 0x24, 0x87, 0x03, 0x7f, 0xfb, 0x5f, 0x79, 0x7c, 0xcd,
    0x56, 0x36, 0x6d, 0x5e, 0xc7, 0x6d, 0xb7, 0x15, 0xe2, 0x70, 0xd8, 0x40,
    0xd8, 0x4a, 0x30, 0x10, 0xa7, 0xb8, 0x30, 0x07, 0x3d, 0x21, 0x73, 0x4f,
    0xeb, 0x7d, 0xb8, 0xdd, 0xf9, 0xbc, 0xf6, 0xa7, 0x9d, 0x14, 0x3e, 0xb3,
    0x8d, 0x5e, 0x01, 0xf2, 0x7b, 0x4e, 0x91, 0x2c, 0x2e, 0xce, 0x98, 0xab,
    0x91, 0x30, 0xa6, 0x69, 0xc2, 0xd8, 0xa1, 0x16, 0x00, 0x6b, 0xc2, 0x4c,
    0x9c, 0x01, 0xe0, 0xeb, 0xae, 0xaf, 0x7c, 0x95, 0x64, 0x28, 0x44, 0x55,
    0x5a, 0x61, 0xf3, 0xa6, 0x0d, 0xd4, 0x2d, 0x29, 0xc5, 0x66, 0x13, 0x39,
    0x77, 0xda, 0xcb, 0xe5, 0xc1, 0x20, 0xa1, 0x40, 0x00, 0x41, 0x10, 0x70,
    0x2a, 0x76, 0x4a, 0x0a, 0x73, 0x58, 0xde, 0xd0, 0xc0, 0xa6, 0x96, 0xc7,
    0x88, 0x1e, 0x3c, 0x82, 0x21, 0xcb, 0xf8, 0xbc, 0x43, 0x44, 0x02, 0xfe,
    0x8c, 0xb9, 0x91, 0x4e, 0x63, 0x99, 0x26, 0x82, 0x2c, 0xcf, 0x03, 0x1c,
    0xd7, 0x9a, 0x4d, 0x05, 0x70, 0x22, 0x49, 0x2b, 0x72, 0xaa, 0xaa, 0xd0,
    0x4f, 0xf5, 0xf0, 0xc0, 0xbd, 0x0f, 0x72, 0x7b, 0x4d, 0x09, 0x96, 0x05,
    0x9e, 0xf3, 0x7e, 0xd2, 0x69, 0x93, 0xe1, 0xe1, 0xcb, 0x78, 0x2e, 0x9e,
    0x07, 0x40, 0x10, 0xa0, 0xe4, 0x96, 0x3c, 0xf2, 0xdd, 0x4e, 0x56, 0x35,
    0xad, 0xc1, 0x3a, 0x77, 0x01, 0x33, 0x99, 0xc4, 0x28, 0x2f, 0xc7, 0x77,
    0xba, 0x27, 0x63, 0x9e, 0x91, 0x30, 0xfd, 0xcc, 0x4f, 0x05, 0x58, 0xa6,
    0x2c, 0x2c, 0x97, 0x45, 0x59, 0xc6, 0x3c, 0xdf, 0xc7, 0x82, 0x85, 0xb7,
    0xf0, 0xca, 0xce, 0x97, 0x09, 0x87, 0xe2, 0x24, 0x93, 0x06, 0x00, 0xf1,
    0xb8, 0x86, 0xaa, 0x8e, 0xb5, 0xb3, 0x53, 0xb1, 0x53, 0x54, 0xe2, 0x42,
    0x71, 0xda, 0xc8, 0xcd, 0x93, 0x59, 0xd7, 0xfc, 0x30, 0x91, 0x23, 0x9d,
    0xd8, 0x0b, 0x0b, 0x11, 0xe7, 0xcf, 0x9f, 0x6c, 0x7e, 0x1d, 0x4d, 0x05,
    0x50, 0x44, 0xe7, 0x58, 0x85, 0x72, 0x45, 0x99, 0x25, 0xb5, 0xb7, 0x53,
    0x5f, 0x5f, 0x4f, 0x28, 0xa8, 0x65, 0x16, 0x24, 0x12, 0xf1, 0x0c, 0x40,
    0x5c, 0x4b, 0xe1, 0x39, 0xef, 0x47, 0x92, 0x44, 0x72, 0x5d, 0x32, 0xf5,
    0x4b, 0x57, 0x62, 0xf6, 0xff, 0x17, 0x80, 0x9c, 0xca, 0xca, 0x39, 0xcd,
    0x67, 0x02, 0xc8, 0x28, 0x6d, 0x99, 0xe4, 0xe5, 0xb9, 0x59, 0xbf, 0x7e,
    0x3d, 0xb1, 0xa8, 0x3e, 0x19, 0x20, 0x3a, 0x6d, 0xa0, 0x61, 0xb3, 0x09,
    0x28, 0x2e, 0x17, 0x42, 0x72, 0xec, 0xa9, 0x45, 0x69, 0xb6, 0x19, 0x97,
    0x05, 0x80, 0x6e, 0xa5, 0xd1, 0xb4, 0x24, 0xa9, 0x94, 0x81, 0x65, 0x5d,
    0x8d, 0xcb, 0x0e, 0x07, 0x47, 0x8f, 0x1d, 0xe2, 0x44, 0xf7, 0xb1, 0x49,
    0xeb, 0xaf, 0x5c, 0x19, 0xa0, 0xa7, 0xa7, 0x13, 0x9b, 0x38, 0x66, 0x6c,
    0x61, 0x91, 0x8d, 0x66, 0x6a, 0x43, 0x00, 0xd2, 0x36, 0x89, 0xe1, 0xe1,
    0x20, 0x91, 0xd1, 0xa2, 0x49, 0xf1, 0x75, 0xdf, 0x7c, 0x88, 0xbb, 0x56,
    0x34, 0xb1, 0xef, 0xa3, 0xbf, 0xf1, 0xf7, 0x0f, 0xda, 0x69, 0x59, 0x7d,
    0x3f, 0xf7, 0xac, 0x5e, 0x4b, 0x34, 0x16, 0x65, 0x68, 0x68, 0x80, 0xb4,
    0x31, 0xfe, 0xde, 0xb3, 0xf3, 0xbf, 0x3e, 0x80, 0xdc, 0xd8, 0xc0, 0x5f,
    0xda, 0xdb, 0xa8, 0xac, 0xfc, 0xf1, 0xb4, 0x7b, 0x25, 0x25, 0x0b, 0x78,
    0xfa, 0xa9, 0x67, 0x01, 0xe8, 0x39, 0x7d, 0x82, 0xbd, 0xed, 0xbb, 0x51,
    0x72, 0x0a, 0xa9, 0xaa, 0x5c, 0x8a, 0x18, 0xe8, 0x1d, 0x07, 0xc8, 0x8e,
    0xe0, 0xba, 0xaf, 0x20, 0xb7, 0xb6, 0x86, 0xce, 0xb3, 0x9f, 0x31, 0xe2,
    0x0b, 0xcf, 0x9a, 0x60, 0x49, 0xdd, 0x72, 0x36, 0x6f, 0x7c, 0x92, 0xba,
    0xda, 0x55, 0x1c, 0x39, 0xf6, 0x31, 0xf6, 0x65, 0x75, 0x59, 0x19, 0xcf,
    0x09, 0x00, 0x60, 0xfb, 0x46, 0x23, 0x3b, 0xff, 0xf0, 0x0a, 0x09, 0xfd,
    0x6a, 0x3b, 0xf9, 0x46, 0x86, 0x09, 0x06, 0xfd, 0x99, 0x6b, 0xcb, 0xb4,
    0x08, 0x8c, 0xc6, 0xf1, 0x0e, 0x07, 0x38, 0x3d, 0xf8, 0x1f, 0x94, 0xf1,
    0xd3, 0x6f, 0xdd, 0x6c, 0x05, 0x00, 0x72, 0x97, 0xd4, 0x71, 0xc6, 0xa5,
    0xf3, 0xcb, 0xdf, 0xec, 0x40, 0xd3, 0x92, 0x58, 0x16, 0xec, 0xfb, 0xf0,
    0x5d, 0xfe, 0xf9, 0xe9, 0x7e, 0x00, 0x52, 0x29, 0x83, 0x40, 0x48, 0xc3,
    0x3b, 0x1c, 0xe6, 0x77, 0x6f, 0xbc, 0x88, 0xfb, 0x91, 0x87, 0x10, 0x66,
    0x18, 0x36, 0xb3, 0x3e, 0xe4, 0x5c, 0x0b, 0xf2, 0x5a, 0x9a, 0x39, 0xdd,
    0x75, 0x94, 0x1f, 0xfe, 0xf4, 0x7b, 0x6c, 0xd9, 0xb0, 0x8d, 0xd6, 0xd6,
    0x8d, 0x88, 0xa2, 0x88, 0x2f, 0x10, 0x23, 0x12, 0xd1, 0xe9, 0x3e, 0xf1,
    0x6f, 0xde, 0xde, 0xb7, 0x0b, 0xdb, 0xea, 0x26, 0x9c, 0x65, 0x65, 0x57,
    0x37, 0x66, 0x59, 0x81, 0xa9, 0x00, 0x96, 0xee, 0xf5, 0xa2, 0x9e, 0x3b,
    0x4b, 0x5e, 0x75, 0x4d, 0x26, 0x98, 0xbb, 0xb2, 0x91, 0xd8, 0x1d, 0x41,
    0x7e, 0xff, 0xe9, 0x5b, 0x88, 0x7b, 0xbc, 0x28, 0x0e, 0x17, 0xa6, 0x65,
    0x92, 0x36, 0xd3, 0xe8, 0xc5, 0xf3, 0x99, 0xf7, 0xd4, 0x16, 0x6c, 0x2e,
    0xd7, 0xe4, 0x44, 0x59, 0xb6, 0xc1, 0xd4, 0x7a, 0x09, 0xc0, 0x26, 0xe0,
    0xa5, 0xdc, 0x3b, 0xaa, 0xab, 0x4b, 0x37, 0x6c, 0xc0, 0xb5, 0x78, 0xf1,
    0xe4, 0xc4, 0xa6, 0x89, 0x65, 0x18, 0x88, 0x76, 0xfb, 0xac, 0x89, 0x63,
    0x7e, 0x3f, 0xa3, 0x03, 0xfd, 0x93, 0x62, 0x81, 0xb6, 0x36, 0x2c, 0x5d,
    0x57, 0x80, 0xc4, 0x44, 0x6c, 0xa6, 0x71, 0x75, 0x06, 0xf8, 0x63, 0x32,
    0xe0, 0xbf, 0x14, 0x3c, 0x72, 0x78, 0x79, 0x7c, 0x70, 0xd0, 0xed, 0x2c,
    0x2b, 0xc3, 0x3e, 0x6f, 0xde, 0x18, 0xa1, 0x20, 0x20, 0x64, 0x31, 0xe5,
    0x52, 0x5a, 0x8c, 0x44, 0x78, 0x72, 0x07, 0xc5, 0x4f, 0x9e, 0x04, 0xc3,
    0xd8, 0x01, 0x64, 0x4e, 0xf5, 0xf5, 0x32, 0x59, 0x40, 0x37, 0xb0, 0x4b,
    0xf7, 0x7a, 0x47, 0x02, 0x87, 0x0e, 0x36, 0xe8, 0x3e, 0x9f, 0x4b, 0x29,
    0x2f, 0x9f, 0x56, 0xea, 0xeb, 0x29, 0x19, 0xd3, 0xd0, 0x23, 0x57, 0x01,
    0x04, 0x49, 0x22, 0x76, 0xfc, 0xb8, 0x85, 0x65, 0xbd, 0x04, 0x18, 0x73,
    0x01, 0x4c, 0xc8, 0x00, 0x8e, 0x02, 0xbb, 0x12, 0x97, 0x2f, 0x6b, 0xfe,
    0x83, 0x1d, 0x0d, 0xe9, 0x70, 0xd8, 0xa9, 0x2c, 0x5a, 0x84, 0xe4, 0x74,
    0xce, 0x0e, 0xa0, 0xc5, 0xd0, 0x23, 0xe3, 0xdf, 0x0c, 0x41, 0x20, 0xd1,
    0xd5, 0x45, 0x72, 0x68, 0xe8, 0x05, 0xa0, 0xe3, 0xda, 0x75, 0xd9, 0x7d,
    0x31, 0xc6, 0x7e, 0x24, 0x0f, 0x61, 0x59, 0xaf, 0xc5, 0xfb, 0xfb, 0xf1,
    0x77, 0x74, 0xac, 0x30, 0xe2, 0x71, 0xbb, 0x52, 0x59, 0x89, 0x28, 0xcb,
    0x33, 0x03, 0xc4, 0xae, 0x02, 0x18, 0x7d, 0x17, 0x89, 0x74, 0x75, 0xb6,
    0x01, 0xd3, 0xc6, 0x6a, 0xb6, 0x00, 0x13, 0x4a, 0x00, 0x07, 0x30, 0xcd,
    0xdd, 0x5a, 0x9f, 0x47, 0x09, 0x1c, 0xec, 0xa8, 0xb7, 0x0c, 0x53, 0x52,
    0x2a, 0x2a, 0x10, 0x6d, 0x93, 0x1b, 0x2a, 0x19, 0x8d, 0xa2, 0xab, 0x11,
    0x84, 0x70, 0x84, 0xc0, 0x07, 0xef, 0x1f, 0x04, 0x1e, 0xe1, 0x9a, 0xd2,
    0xdf, 0x28, 0xc0, 0x84, 0xa2, 0xc0, 0x47, 0x56, 0x3a, 0xbd, 0x27, 0x76,
    0xbe, 0xb7, 0x20, 0x70, 0xf8, 0xf0, 0x52, 0x41, 0x94, 0x04, 0x65, 0xd1,
    0xa2, 0xcc, 0x01, 0xd5, 0x63, 0x51, 0xd2, 0xe1, 0x30, 0xbe, 0xb7, 0xfe,
    0xec, 0x01, 0xee, 0x1f, 0xdf, 0x33, 0x4d, 0x37, 0x0a, 0x30, 0xa1, 0x51,
    0xe0, 0x3d, 0x2b, 0x99, 0x7c, 0x57, 0x3d, 0x73, 0xa6, 0x2c, 0xf4, 0x59,
    0x57, 0xb5, 0xe8, 0x74, 0x22, 0x17, 0x14, 0x10, 0x1f, 0x1c, 0x60, 0xe8,
    0xcd, 0x37, 0x47, 0x31, 0x8c, 0x56, 0x60, 0xf0, 0x26, 0x7d, 0xb2, 0xd6,
    0xdd, 0xc0, 0x81, 0x71, 0xb0, 0x6e, 0xa0, 0x75, 0xae, 0x0d, 0xff, 0x03,
    0xed, 0xb9, 0xfb, 0x1d, 0x80, 0xeb, 0x9a, 0x91, 0x00, 0x00, 0x00, 0x00,
    0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

#include <iostream>
#include <limits>
using namespace std;
#include <qtimer.h>
#include <qtooltip.h>
#include <qimage.h>
#include <qwidgetaction.h>
#include <qboxlayout.h>
#include <Music/Music.h>

void GLErrorHistory::Note::init()
{
	min_err = numeric_limits<float>::max();
	max_err = -numeric_limits<float>::max();
	avg_err = 0.0f;
}
GLErrorHistory::Note::Note(int h)
	: ht(h)
{
	init();
}
GLErrorHistory::Note::Note(int h, int num, int den)
	: ht(h)
{
	init();
	factor = QString::number(num)+"/"+QString::number(den);
}
GLErrorHistory::Note::Note(int h, float cents)
	: ht(h)
{
	init();
	factor = QString::number(cents);
}
QString GLErrorHistory::Note::getName() const
{
	return QString::fromStdString(Music::h2n(ht))+factor;
}
void GLErrorHistory::Note::addError(float err)
{
	min_err = (err<min_err)?err:min_err;
	max_err = (err>max_err)?err:max_err;

	if(!errors.empty())
		avg_err *= errors.size();

	errors.push_back(err);

	avg_err += err;
	avg_err /= errors.size();
}

GLErrorHistory::GLErrorHistory(QWidget* parent)
: QGLWidget(parent)
, View(tr("Error history"), this)
, m_font("Helvetica")
{
    // settings
	QPixmap img;
	img.loadFromData(g_icon_error_graph, sizeof(g_icon_error_graph), "PNG");
	setting_show->setIcon(QIcon(img));
	setting_show->setChecked(true);

	setting_keep = new QAction(tr("Keep previous notes"), this);
	setting_keep->setCheckable(true);
	setting_keep->setChecked(false);
	connect(setting_keep, SIGNAL(toggled(bool)), this, SLOT(keepPreviousNotes(bool)));
	m_popup_menu.addAction(setting_keep);

	setting_useCents = new QAction(tr("Use cents"), this);
	setting_useCents->setCheckable(true);
	setting_useCents->setChecked(true);
	connect(setting_useCents, SIGNAL(toggled(bool)), this, SLOT(update()));
	m_popup_menu.addAction(setting_useCents);

	QHBoxLayout* scaleActionLayout = new QHBoxLayout(&m_popup_menu);

	QLabel* scaleActionTitle = new QLabel(tr("Scale range"), &m_popup_menu);
	scaleActionLayout->addWidget(scaleActionTitle);

	setting_spinScale = new QSpinBox(&m_popup_menu);
	setting_spinScale->setMinimum(5);
	setting_spinScale->setMaximum(50);
	setting_spinScale->setSingleStep(1);
	setting_spinScale->setValue(50);
	setting_spinScale->setToolTip(tr("Scale range (in cents)"));
	connect(setting_spinScale, SIGNAL(valueChanged(int)), this, SLOT(update()));
	scaleActionLayout->addWidget(setting_spinScale);

	QWidget* scaleActionWidget = new QWidget(&m_popup_menu);
	scaleActionWidget->setLayout(scaleActionLayout);

	QWidgetAction* scaleAction = new QWidgetAction(&m_popup_menu);
	scaleAction->setDefaultWidget(scaleActionWidget);
	m_popup_menu.addAction(scaleAction);
}

void GLErrorHistory::save()
{
	s_settings->setValue("keep", setting_keep->isChecked());
	s_settings->setValue("useCents", setting_useCents->isChecked());
	s_settings->setValue("spinScale", setting_spinScale->value());
}
void GLErrorHistory::load()
{
	setting_keep->setChecked(s_settings->value("keep", setting_keep->isChecked()).toBool());
	setting_useCents->setChecked(s_settings->value("useCents", setting_useCents->isChecked()).toBool());
	setting_spinScale->setValue(s_settings->value("spinScale", setting_spinScale->value()).toInt());
}
void GLErrorHistory::clearSettings()
{
	s_settings->remove("keep");
	s_settings->remove("useCents");
	s_settings->remove("spinScale");
}

void GLErrorHistory::addNote(GLErrorHistory::Note note)
{
	m_notes.push_back(note);

	if(!setting_keep->isChecked())
		while(m_notes.size()>1)
			m_notes.pop_front();
}
void GLErrorHistory::addError(float err)
{
	m_notes.back().addError(err);
}

void GLErrorHistory::keepPreviousNotes(bool keep)
{
	if(!keep)
		while(m_notes.size()>1)
			m_notes.pop_front();
}

void GLErrorHistory::initializeGL()
{
    // Set the clear color to black
    glClearColor(1.0, 1.0, 1.0, 0.0);

    // glShadeModel( GL_FLAT );
    glShadeModel( GL_SMOOTH );

    glLoadIdentity();
}

void GLErrorHistory::drawTicksCent(int r, int ticks_size)
{
	// only work within range that is a pure multiple of r
	float range = int(setting_spinScale->value()/r)*r;

	float scale = 50.0f/setting_spinScale->value();
	if((height()-ticks_size)*r/100.0f*scale>2)
	{
		for(float i=-range; i<=range; i+=r)
		{
            int y = height()/2 + int(height()*i/100.0f*scale);
            glVertex2i(ticks_size, y);
            glVertex2i(width(), y);
		}
	}
}
void GLErrorHistory::drawTextTickCent(int r, int dy)
{
	// only work within range that is a pure multiple of r
	int range = int(setting_spinScale->value()/r)*r;

    m_font.setPixelSize(14);
    QFontMetrics fm(m_font);

	float scale = 50.0f/setting_spinScale->value();
	QString txt;
    for(int i=-range; i<=range; i+=r)
	{
		txt = QString::number(i);
		if(i>=0) txt = QString("  ")+txt;
		if(i==0) txt = QString("  ")+txt;
        int y = height()/2 - int(height()*i/100.0f*scale);
        if(y>fm.xHeight() && y<height()-fm.xHeight())
            renderText(2, y+ fm.xHeight()/2, txt, m_font);
    }
}

//void GLErrorHistory::paintEvent(QPaintEvent * event){
//    QPainter painter;
//    painter.begin(this);
//    QBrush background = QBrush(Qt::white);
//    painter.fillRect(rect(), background);
//    painter.end();
//}

void GLErrorHistory::paintGL()
{
// 	cout << "GLErrorHistory::paintGL " << m_notes.size() << endl;

    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(1.0f);

    // name
    glColor3f(0.75,0.75,0.75);
    m_font.setPixelSize(20);
    renderText(2, 20, tr("Error"), m_font);

    int char_size = 9;
    int ticks_size = 2+3*char_size;
    int dy = char_size/2;

    // horiz lines
    if(setting_useCents->isChecked())
    {
        glBegin(GL_LINES);
        float gray = 0.87;
// 		glColor3f(gray, gray, gray);
// 		drawTicksCent(1, ticks_size);
        gray = 0.875;
        glColor3f(gray, gray, gray);
        drawTicksCent(2, ticks_size);
        gray = 0.75;
        glColor3f(gray, gray, gray);
        drawTicksCent(10, ticks_size);
        glEnd();
    }
    else
    {
        glBegin(GL_LINES);
            float gray = 0.5;
            glColor3f(gray, gray, gray);
            glVertex2i(ticks_size,  height()/2);
            glVertex2i(width(),  height()/2);
            gray = 0.75;
            glColor3f(gray, gray, gray);
            glVertex2i(ticks_size,  height()/4);
            glVertex2i(width(),  height()/4);
            glVertex2i(ticks_size,  3*height()/4);
            glVertex2i(width(),  3*height()/4);
            gray = 0.87;
            glColor3f(gray, gray, gray);
            glVertex2i(ticks_size,  height()/8);
            glVertex2i(width(),  height()/8);
            glVertex2i(ticks_size,  7*height()/8);
            glVertex2i(width(),  7*height()/8);
            glVertex2i(ticks_size,  3*height()/8);
            glVertex2i(width(),  3*height()/8);
            glVertex2i(ticks_size,  5*height()/8);
            glVertex2i(width(),  5*height()/8);
        glEnd();
    }

    // text marks
    float gray = 0.5;
    glColor3f(gray, gray, gray);
    if(setting_useCents->isChecked())
    {
        int grad = 10;
        if(setting_spinScale->value() <= 25) grad=5;
        if(setting_spinScale->value() <= 10) grad=1;
        drawTextTickCent(grad, dy);
    }
    else
    {
        m_font.setPixelSize(14);
        QFontMetrics fm(m_font);
        string sfraq, sufraq;
        sufraq = string("1/")+QString::number(int(50/setting_spinScale->value())*2).toStdString();
        sfraq = string("-")+sufraq;
        renderText(2, 3*height()/4-dy+fm.xHeight(), QString(sfraq.c_str()), m_font);
        sfraq = string("+")+sufraq;
        renderText(2, height()/4-dy+fm.xHeight(), QString(sfraq.c_str()), m_font);

        sufraq = string("1/")+QString::number(int(50/setting_spinScale->value())*4).toStdString();
        sfraq = string("-")+sufraq;
        renderText(2, 5*height()/8-dy+fm.xHeight(), QString(sfraq.c_str()), m_font);
        sfraq = string("+")+sufraq;
        renderText(2, 3*height()/8-dy+fm.xHeight(), QString(sfraq.c_str()), m_font);
    }

    // errors
    if(!m_notes.empty())
    {
        int total_size = 0;
        for(size_t i=0; i<m_notes.size(); i++)
            total_size += int(m_notes[i].errors.size())-1;

        float step = float(width()-ticks_size)/total_size;

//		cout << "total_size=" << total_size << " step=" << step << endl;

        int curr_total = 0;
        for(size_t i=0; i<m_notes.size(); i++)
        {
            float x = ticks_size+step*curr_total;

            // if it's not the first, add a separation
            if(i>0)
            {
                glColor3f(0.75,0.75,0.75);
                glLineWidth(1.0f);
                glBegin(GL_LINES);
                glVertex2f(x, 0);	glVertex2f(x, height());
                glEnd();
            }

            // the note name
            string str = m_notes[i].getName().toStdString();
            glColor3f(0.0,0.0,1.0);
            m_font.setPixelSize(14);
            renderText(x+2, height()-2, QString(str.c_str()), m_font);

            // draw the error graph
            glColor3f(0.0f,0.0f,0.0f);
            glLineWidth(2.0f);
            glBegin(GL_LINE_STRIP);

            if(setting_useCents->isChecked())
            {
                float scale = 50.0f/setting_spinScale->value();
                glVertex2f(x, int(scale*m_notes[i].errors[0]*height()) + height()/2);
                for(int j=1; j<int(m_notes[i].errors.size()); j++)
                    glVertex2f(x+j*step, scale*m_notes[i].errors[j]*height() + height()/2);
            }
            else
            {
                float scale = int(50/setting_spinScale->value());
                glVertex2f(x, int((scale*m_notes[i].errors[0])*height()) + height()/2);
                for(int j=1; j<int(m_notes[i].errors.size()); j++)
                    glVertex2f(x+j*step, (scale*m_notes[i].errors[j])*height() + height()/2);
            }
            glEnd();

            curr_total += int(m_notes[i].errors.size())-1;
        }
    }

    glFlush();
}

void GLErrorHistory::resizeGL( int w, int h )
{
    // Set the new viewport size
    glViewport(0, 0, (GLint)w, (GLint)h);

    // Choose the projection matrix to be the matrix
    // manipulated by the following calls
    glMatrixMode(GL_PROJECTION);

    // Set the projection matrix to be the identity matrix
    glLoadIdentity();

    // Define the dimensions of the Orthographic Viewing Volume
    glOrtho(0.0, w, 0.0, h, 0.0, 1.0);

    // Choose the modelview matrix to be the matrix
    // manipulated by further calls
    glMatrixMode(GL_MODELVIEW);
}

