#include <gtest/gtest.h>
#include "map.h"
#include "element.h"
#include "track.h"

TEST(MapTest, straightTrackListToQString) {
    Map *map = new Map();
    map->createAddStraightTrack(StraightType::STRAIGHTH,1,2);
    EXPECT_EQ(map->straightTrackListToQStringForSaving().toStdString(),"SH,1,2,200,100,0,0,0\n");

    map->createAddStraightTrack(StraightType::STRAIGHTV,100,6);
    EXPECT_EQ(map->straightTrackListToQStringForSaving().toStdString(),"SH,1,2,200,100,0,0,0\nSV,100,6,200,100,0,0,0\n");
    map->createAddStraightTrack(StraightType::STRAIGHTLEFTUP,542671,-232342);
    EXPECT_EQ(map->straightTrackListToQStringForSaving().toStdString(),"SH,1,2,200,100,0,0,0\nSV,100,6,200,100,0,0,0\nSLU,542671,-232342,200,100,0,0,0\n");
}
