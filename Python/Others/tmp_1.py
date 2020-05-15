import pygame
cur_path = './Others/'


if __name__ == "__main__":
    pygame.init()
    content = '得分'
    fonts = pygame.font.get_fonts()
    for font_name in fonts:
        font = pygame.font.SysFont(font_name, 48)
        font_img = font.render(content, True, (0, 0, 0))
        print(type(font_img))
        pygame.image.save(font_img, cur_path + 'fonts/' + font_name + '.png')
