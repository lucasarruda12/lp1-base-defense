#include <UIElements/Screen.hpp>
#include <AssetManager.hpp>
#include <Constants.hpp>

#include <string>
using std::string;

Screen::Screen(const string& n_title, const string& n_subtitle)
:title(n_title, AssetManager::gameFont)
,subtitle1(n_subtitle, AssetManager::gameFont)
,subtitle2("", AssetManager::gameFont)
{
  sf::FloatRect textBounds = title.getLocalBounds();
  title.setOrigin(textBounds.width/2.f, textBounds.height/2.f);
  title.setPosition(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));
  title.setFillColor(sf::Color::Red);

  subtitle1.setCharacterSize(16);
  textBounds = subtitle1.getLocalBounds();
  subtitle1.setOrigin(textBounds.width/2.f, textBounds.height/2.f);
  subtitle1.setPosition(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 40));
  subtitle1.setFillColor(sf::Color::White);
}

Screen::Screen(const string& n_title, const string& n_subtitle1, const string& n_subtitle2)
:title(n_title, AssetManager::gameFont)
,subtitle1(n_subtitle1, AssetManager::gameFont)
,subtitle2(n_subtitle2, AssetManager::gameFont)
{
  sf::FloatRect textBounds = title.getLocalBounds();
  title.setOrigin(textBounds.width/2.f, textBounds.height/2.f);
  title.setPosition(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));
  title.setFillColor(sf::Color::Red);

  subtitle1.setCharacterSize(16);
  textBounds = subtitle1.getLocalBounds();
  subtitle1.setOrigin(textBounds.width/2.f, textBounds.height/2.f);
  subtitle1.setPosition(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 40));
  subtitle1.setFillColor(sf::Color::White);

  subtitle2.setCharacterSize(16);
  textBounds = subtitle2.getLocalBounds();
  subtitle2.setOrigin(textBounds.width/2.f, textBounds.height/2.f);
  subtitle2.setPosition(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 65));
  subtitle2.setFillColor(sf::Color::White);
}

void Screen::render(sf::RenderWindow& window)
{
  window.draw(title);
  window.draw(subtitle1);
  window.draw(subtitle2);
}