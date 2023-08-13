#include "UIPanel.h"
#include <SFML/Graphics.hpp>
using namespace sf;

UIPanel::UIPanel(Vector2i res, int x, int y, float width, float height, int alpha, int red, int green, int blue)
{
	m_UIPanel.setFillColor(sf::Color(red, green, blue, alpha));

	m_UIPanel.setSize(Vector2f(width, height));
}

vector<shared_ptr<Button>> UIPanel::getButtons()
{
	return m_Buttons;
}

//void UIPanel::addButton(float x, float y, int width, int height, int red, int green, int blue, string label)
//{
//	m_Buttons.push_back(make_shared<Button>(Vector2f(x, y), width, height, red, green, blue, label));
//}

void UIPanel::draw(RenderWindow& window)
{
	if (!m_Hidden) 
	{
		window.draw(m_UIPanel);

		for (auto it = m_Buttons.begin(); it != m_Buttons.end(); ++it)
		{
			//(*it)->draw(window);
		}
	}
}
void UIPanel::show()
{
	m_Hidden = false;
}

void UIPanel::hide()
{
	m_Hidden = true;
}