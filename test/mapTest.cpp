#include <gtest/gtest.h>
#include <QFile>
#include <QIODevice>
#include "map.h"
#include "element.h"
#include "track.h"

TEST(MapSavingQStringTest, straightTrackListToQString) {
    Map *map = new Map();
    map->createAddStraightTrack(StraightType::STRAIGHTH,1,2);
    EXPECT_EQ(map->straightTrackListToQStringForSaving().toStdString(),"SH,1,2,200,100,0,0,0\n");
    map->createAddStraightTrack(StraightType::STRAIGHTV,100,6);
    EXPECT_EQ(map->straightTrackListToQStringForSaving().toStdString(),"SH,1,2,200,100,0,0,0\nSV,100,6,200,100,0,0,0\n");
    map->createAddStraightTrack(StraightType::STRAIGHTLEFTUP,542671,-232342);
    EXPECT_EQ(map->straightTrackListToQStringForSaving().toStdString(),"SH,1,2,200,100,0,0,0\nSV,100,6,200,100,0,0,0\nSLU,542671,-232342,200,100,0,0,0\n");
}

TEST(MapSavingQStringTest, directedTrackListToQString) {
    Map *map = new Map();
    map->createAddDirectedTrack(DirectedType::DIRECTEDLEFT,1,2);
    EXPECT_EQ(map->directedTrackListToQStringForSaving().toStdString(),"DL,1,2,200,100,0,0\n");
    map->createAddDirectedTrack(DirectedType::DIRECTEDLEFTUP,100,6);
    EXPECT_EQ(map->directedTrackListToQStringForSaving().toStdString(),"DL,1,2,200,100,0,0\nDLU,100,6,200,100,0,0\n");
    map->createAddDirectedTrack(DirectedType::DIRECTEDRIGHTDOWN,542671,-232342);
    EXPECT_EQ(map->directedTrackListToQStringForSaving().toStdString(),"DL,1,2,200,100,0,0\nDLU,100,6,200,100,0,0\nDRD,542671,-232342,200,100,0,0\n");
}

TEST(MapSavingQStringTest, curvedTrackListToQString) {
    Map *map = new Map();
    map->createAddCurvedTrack(CurvedType::CURVE1,1,2);
    EXPECT_EQ(map->curvedTrackListToQStringForSaving().toStdString(),"C1,1,2,200,100\n");
    map->createAddCurvedTrack(CurvedType::CURVE6,100,6);
    EXPECT_EQ(map->curvedTrackListToQStringForSaving().toStdString(),"C1,1,2,200,100\nC6,100,6,200,100\n");
    map->createAddCurvedTrack(CurvedType::TIGHTCURVE4,542671,-232342);
    EXPECT_EQ(map->curvedTrackListToQStringForSaving().toStdString(),"C1,1,2,200,100\nC6,100,6,200,100\nTC4,542671,-232342,200,100\n");
}

TEST(MapSavingQStringTest, linkedTrackListToQString) {
	Map *map = new Map();
	map->createAddLinkedTrack(LinkedType::LINKRIGHT,1,2);
	EXPECT_EQ(map->linkedTrackListToQStringForSaving().toStdString(),"LR,1,2,200,100,0\n");
	map->createAddLinkedTrack(LinkedType::LINKUP,100,6);
	EXPECT_EQ(map->linkedTrackListToQStringForSaving().toStdString(),"LR,1,2,200,100,0\nLU,100,6,200,100,0\n");
	map->createAddLinkedTrack(LinkedType::LINKLEFTDOWN,542671,-232342);
	EXPECT_EQ(map->linkedTrackListToQStringForSaving().toStdString(),"LR,1,2,200,100,0\nLU,100,6,200,100,0\nLLD,542671,-232342,200,100,0\n");
}
