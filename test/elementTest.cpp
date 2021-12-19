#include <gtest/gtest.h>
#include "../element.h"



TEST(ElementToQStringTest, ElementToQStringOutput) {
	std::shared_ptr<NamedLocation> namedLocation1(new NamedLocation(1,2));
	std::shared_ptr<NamedLocation> namedLocation2(new NamedLocation(100,6));
	std::shared_ptr<NamedLocation> namedLocation3(new NamedLocation(542671,-232342));
	EXPECT_EQ(namedLocation1->locationToQString().toStdString(),"1,2");
	EXPECT_EQ(namedLocation2->locationToQString().toStdString(),"100,6");
	EXPECT_EQ(namedLocation3->locationToQString().toStdString(),"542671,-232342");
}
