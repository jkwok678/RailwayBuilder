#include <gtest/gtest.h>
#include <QApplication>
#include "element.h"



TEST(ElementTest, elementLocationToQStringOutput) {
	std::shared_ptr<Element> namedLocation1(new NamedLocation(1,2));
	std::shared_ptr<Element> namedLocation2(new NamedLocation(100,6));
	std::shared_ptr<Element> namedLocation3(new NamedLocation(542671,-232342));
	EXPECT_EQ(namedLocation1->locationToQString().toStdString(),"1,2");
	EXPECT_EQ(namedLocation2->locationToQString().toStdString(),"100,6");
	EXPECT_EQ(namedLocation3->locationToQString().toStdString(),"542671,-232342");
}


TEST(TextTest, TextToQStringOutput) {

}

TEST(NamedLocationTest, namedLocationToQStringOutput) {
	std::shared_ptr<NamedLocation> namedLocation1(new NamedLocation(1,2));
	std::shared_ptr<NamedLocation> namedLocation2(new NamedLocation(100,6));
	std::shared_ptr<NamedLocation> namedLocation3(new NamedLocation(542671,-232342));
	EXPECT_EQ(namedLocation1->toQString().toStdString(),"NamedLocation,1,2");
	EXPECT_EQ(namedLocation2->toQString().toStdString(),"NamedLocation,100,6");
	EXPECT_EQ(namedLocation3->toQString().toStdString(),"NamedLocation,542671,-232342");

}

TEST(ConcourseToQStringTest, concourseToQStringOutput) {
	std::shared_ptr<Concourse> concourse1(new Concourse(84,264));
	std::shared_ptr<Concourse> concourse2(new Concourse(102310,6000000));
	std::shared_ptr<Concourse> concourse3(new Concourse(-23542671,-23232342));
	EXPECT_EQ(concourse1->toQString().toStdString(),"Concourse,84,264");
	EXPECT_EQ(concourse2->toQString().toStdString(),"Concourse,102310,6000000");
	EXPECT_EQ(concourse3->toQString().toStdString(),"Concourse,-23542671,-23232342");

}

TEST(ParapetToQStringTest, parapetToQStringOutput) {
	std::shared_ptr<Parapet> parapet1(new Parapet(ParapetType::PARAPET1,1,2));
	std::shared_ptr<Parapet> parapet2(new Parapet(ParapetType::PARAPET12,100,6));
	std::shared_ptr<Parapet> parapet3(new Parapet(ParapetType::PARAPET5,542671,-232342));
	EXPECT_EQ(parapet1->toQString().toStdString(),"Parapet,parapet_1,1,2");
	EXPECT_EQ(parapet2->toQString().toStdString(),"Parapet,parapet_12,100,6");
	EXPECT_EQ(parapet3->toQString().toStdString(),"Parapet,parapet_5,542671,-232342");

}
