/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package snakeV2;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Random;

/**
 *
 * @author Ngua gia
 */
public class Token {

    private int x, y, score;
    private Snake snake;
    Color[] listColors = {Color.GREEN, Color.BLUE, Color.RED, Color.WHITE, Color.YELLOW, Color.CYAN};
    int i = 0;

    public Token(Snake s) {
        x = (int) (Math.random() * 395);
        y = (int) (Math.random() * 395);
        snake = s;
    }

    public void changePosition() {
        x = (int) (Math.random() * 395);
        y = (int) (Math.random() * 395);
    }

    public int getScore() {
        return score;
    }

    public void draw(Graphics g) {
        g.setColor(this.listColors[i]);
        g.fillRect(x, y, 6, 6);
    }

    public boolean snakeCollision() {
        int snakeX = snake.getX() + 2;
        int snakeY = snake.getY() + 2;
        if (snakeX >= x - 1 && snakeX <= (x + 7)) {
            if (snakeY >= y - 1 && snakeY <= (y + 7)) {
                changePosition();
                score++;
                snake.setElongate(true);
                Random rand = new Random();
                if (snake.speed > 10 && (i == 0 || i == 1 || i == 2)) {
                    snake.speed = snake.speed - 5;
                }
                 if (snake.speed < 40 && (i == 3 || i == 4 || i == 5)) {
                    snake.speed = snake.speed + 5;
                }

                i = (int) rand.nextInt(6);
                return true;
            }
        }
        return false;
    }
}
