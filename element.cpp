#include "element.h"


//Element class implementation.

//Private

QString Element::getLocationXToQString()
{
	return QString::number(locationX);
}

QString Element::getLocationYToQString()
{
	return QString::number(locationY);
}

//Public

Element::Element()
{

}

Element::Element(int currentX, int currentY)
{
	locationX = currentX;
	locationY = currentY;
}

int Element::getLocationX() const
{
	return locationX;
}

void Element::setLocationX(int newLocationX)
{
	locationX = newLocationX;
}

int Element::getLocationY() const
{
	return locationY;
}

void Element::setLocationY(int newLocationY)
{
	locationY = newLocationY;
}

QString Element::locationToQString()
{
	QString locationQString = "";
	locationQString.append(getLocationXToQString());
	locationQString.append(",");
	locationQString.append(getLocationYToQString());
	return locationQString;
}


//Text class implementation.


Text::Text(int newLocationX, int newLocationY, QString newReadableText, QFont newFont)
{
	locationX = newLocationX;
	locationY = newLocationY;
	readableText = newReadableText;
	editableX = locationX + fontSize;
	editableY = locationY + fontSize;
	font = newFont;
}

int Text::getEditableX() const
{
	return editableX;
}

void Text::setEditableX(int newEditableX)
{
	editableX = newEditableX;
}

int Text::getEditableY() const
{
	return editableY;
}

void Text::setEditableY(int newEditableY)
{
	editableY = newEditableY;
}

int Text::getFontSize() const
{
	return fontSize;
}

void Text::setFontSize(int newFontSize)
{
	fontSize = newFontSize;
}

QString Text::getReadableText() const
{
	return readableText;
}

void Text::setReadableText(const QString& newReadableText)
{
	readableText = newReadableText;
}

QFont Text::getFont() const
{
	return font;
}

void Text::setFont(const QFont newFont)
{
	font = newFont;
}

QString Text::toQString()
{
	QString textQString = "Text";
	textQString.append(",");
	textQString.append(locationToQString());
	textQString.append(",");
	textQString.append(readableText);
	textQString.append(",");
	textQString.append(font.toString());
	return textQString;
}

QString Text::toQStringForSave()
{
	QString saveTextQString = locationToQString();
	saveTextQString.append(",");
	saveTextQString.append(readableText);
	saveTextQString.append(",");
	saveTextQString.append(font.toString());
	return saveTextQString;
}


//NamedElement class implementation.


NamedElement::NamedElement()
{

}

bool NamedElement::getNamed() const
{
	return named;
}

void NamedElement::setNamed(bool newNamed)
{
	named = newNamed;
}

std::shared_ptr<Text> NamedElement::getText()
{
	return text;
}

void NamedElement::setText(std::shared_ptr<Text> &newText)
{
	text = newText;
}

QString NamedElement::toQString()
{
	QString namedElementQString = "NamedElement";
	namedElementQString.append(",");
	namedElementQString.append(locationToQString());
	if(text != nullptr)
	{
		namedElementQString.append(",");
		namedElementQString.append(text->toQString());
	}
	return namedElementQString;

}


//NamedLocation class implementation.


NamedLocation::NamedLocation(int newLocationX, int newLocationY)
{
	locationX = newLocationX;
	locationY = newLocationY;
	named = false;
	text = nullptr;


}

QString NamedLocation::toQString()
{
	QString namedLocationQString = "NamedLocation";
	namedLocationQString.append(",");
	namedLocationQString.append(locationToQString());
	if(text != nullptr)
	{
		namedLocationQString.append(",");
		namedLocationQString.append(text->toQString());
	}
	return namedLocationQString;
}

QString NamedLocation::toQStringForSave()
{
	QString saveNamedLocationQString = locationToQString();
	if(text != nullptr)
	{
		saveNamedLocationQString.append(",");
		saveNamedLocationQString.append(text->toQString());
	}
	return saveNamedLocationQString;
}


//Concourse class implementation.


Concourse::Concourse(int newLocationX, int newLocationY)
{
	locationX = newLocationX;
	locationY = newLocationY;
	named = false;
	text = nullptr;

}

QString Concourse::toQString()
{
	QString concourseQString = "Concourse";
	concourseQString.append(",");
	concourseQString.append(locationToQString());
	if(text != nullptr)
	{
		concourseQString.append(",");
		concourseQString.append(text->toQString());
	}
	return concourseQString;
}

QString Concourse::toQStringForSave()
{
	QString saveConcourseQString = locationToQString();
	if(text != nullptr)
	{
		saveConcourseQString.append(",");
		saveConcourseQString.append(text->toQString());
	}
	return saveConcourseQString;
}


//Parapet class implementation.


Parapet::Parapet(ParapetType newParapetType, int newLocationX, int newLocationY)
{
	parapetType = newParapetType;
	locationX = newLocationX;
	locationY = newLocationY;
}

ParapetType Parapet::getParapetType() const
{
	return parapetType;
}

void Parapet::setParapetType(const ParapetType &newParapetType)
{
	parapetType = newParapetType;
}

QString Parapet::parapetTypeToQString()
{
	QString parapetTypeQString;
	switch (parapetType)
	{
	case ParapetType::PARAPET1:
        parapetTypeQString = "p1";
		break;
	case ParapetType::PARAPET2:
        parapetTypeQString = "p2";
		break;
	case ParapetType::PARAPET3:
        parapetTypeQString = "p3";
		break;
	case ParapetType::PARAPET4:
        parapetTypeQString = "p4";
		break;
	case ParapetType::PARAPET5:
        parapetTypeQString = "p5";
		break;
	case ParapetType::PARAPET6:
        parapetTypeQString = "p6";
		break;
	case ParapetType::PARAPET7:
        parapetTypeQString = "p7";
		break;
	case ParapetType::PARAPET8:
        parapetTypeQString = "p8";
		break;
	case ParapetType::PARAPET9:
        parapetTypeQString = "p9";
		break;
	case ParapetType::PARAPET10:
        parapetTypeQString = "p10";
		break;
	case ParapetType::PARAPET11:
        parapetTypeQString = "p11";
		break;
	case ParapetType::PARAPET12:
        parapetTypeQString = "p12";
		break;
	case ParapetType::PARAPET13:
        parapetTypeQString = "p13";
		break;
	case ParapetType::PARAPET14:
        parapetTypeQString = "p14";
		break;
	case ParapetType::PARAPET15:
        parapetTypeQString = "p15";
		break;
	case ParapetType::PARAPET16:
        parapetTypeQString = "p16";
		break;
	case ParapetType::PARAPET17:
        parapetTypeQString = "p17";
		break;
	case ParapetType::PARAPET18:
        parapetTypeQString = "p18";
		break;
	case ParapetType::PARAPET19:
        parapetTypeQString = "p19";
		break;
	case ParapetType::PARAPET20:
        parapetTypeQString = "p20";
		break;
	case ParapetType::PARAPET21:
        parapetTypeQString = "p21";
		break;
	case ParapetType::PARAPET22:
        parapetTypeQString = "p22";
		break;
	case ParapetType::PARAPET23:
        parapetTypeQString = "p23";
		break;
	case ParapetType::PARAPET24:
        parapetTypeQString = "p24";
		break;
	case ParapetType::PARAPET25:
        parapetTypeQString = "p25";
		break;
	case ParapetType::PARAPET26:
        parapetTypeQString = "p26";
		break;
	case ParapetType::PARAPET27:
        parapetTypeQString = "p27";
		break;
	case ParapetType::PARAPET28:
        parapetTypeQString = "p28";
		break;
	}
	return parapetTypeQString;
}

QString Parapet::toQString()
{
	QString parapetQString = "Parapet";
	parapetQString.append(",");
	parapetQString.append(parapetTypeToQString());
	parapetQString.append(",");
	parapetQString.append(locationToQString());
	return parapetQString;
}

QString Parapet::toQStringForSave()
{
	QString saveParapetQString = parapetTypeToQString();
	saveParapetQString.append(",");
	saveParapetQString.append(locationToQString());
	return saveParapetQString;
}
