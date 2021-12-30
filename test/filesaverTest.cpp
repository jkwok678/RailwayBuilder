#include <gtest/gtest.h>
#include <vector>
#include <memory>
#include <QFile>
#include <QIODevice>
#include "map.h"
#include "element.h"
#include "track.h"
#include "filesaver.h"


TEST(FilesaverSaveFileTest, writeStraightTrackDirectedTrack) {
	Map *map = new Map();
	map->createAddStraightTrack(StraightType::STRAIGHTH,1,2);
	map->createAddStraightTrack(StraightType::STRAIGHTV,100,6);
	std::shared_ptr<StraightTrack> straightOne = map->getStraightTrackAt(1,2);
	//straightOne->setPlatform1(true);
	Filesaver *filesaver = new Filesaver("./test_result.rly2");
	filesaver->saveRailwayAs(map);
}
