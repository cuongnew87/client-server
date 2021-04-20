/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package snakeV2;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

/**
 *
 * @author Ngua gia
 */
public class SnakeGame extends Applet implements Runnable, KeyListener {

    Graphics gfx;
    Image img;
    Thread thread;
    Snake snake;
    boolean gameOver;
    boolean checkMusic;
    Token token1;
    Token token2;
    Music mc;

    public void init() {
        this.resize(400, 400);
        gameOver = false;
        img = createImage(400, 400);
        gfx = img.getGraphics();
        this.addKeyListener(this);
        snake = new Snake();
        token1 = new Token(snake);
        token2 = new Token(snake);
        mc = new Music();
//        String musicLocation = "E:\\Documents\\NetBeansProjects\\Snake\\Music\\Music1.wav";
//        mc.playMusic(musicLocation);
        checkMusic = true;
        thread = new Thread(this);
        thread.start();
    }

    public void paint(Graphics g) {
        gfx.setColor(Color.pink);
        gfx.fillRect(0, 0, 400, 400);
        if (!gameOver) {
            snake.draw(gfx);
            token1.draw(gfx);
            token2.draw(gfx);
        } else {
            gfx.setColor(Color.BLACK);
            gfx.drawString("Game Over", 180, 70);
            gfx.drawString("Press R to restart", 180, 90);
            gfx.drawString("Press P to pause music", 180, 110);
            gfx.drawString("Press O to resume music", 180, 130);
            gfx.drawString("Choose music after restart game", 180, 150);
            gfx.drawString("1 - Music1", 180, 170);
            gfx.drawString("2 - Music2", 180, 190);
            gfx.drawString("3 - Music3", 180, 210);
            gfx.drawString("Score " + ((int) (token1.getScore() + token2.getScore())), 180, 230);
            mc.stopMusic();
            checkMusic = false;
        }

        g.drawImage(img, 0, 0, null);
    }

    public void update(Graphics g) {
        paint(g);
    }

    public void repaint(Graphics g) {
        paint(g);
    }

    public void run() {
        for (;;) {
            if (!gameOver) {
                snake.move();
                this.checkGameOver();
                token1.snakeCollision();
                token2.snakeCollision();
            }

            this.repaint();
            try {
                Thread.sleep(snake.speed);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        }
    }

    public void keyTyped(KeyEvent e) {

    }

    public void checkGameOver() {
        if (snake.getX() < 0 || snake.getX() > 396) {
            gameOver = true;
        }
        if (snake.getY() < 0 || snake.getY() > 396) {
            gameOver = true;
        }
        if (snake.snakeCollistion()) {
            gameOver = true;
        }
    }

    void restartGame() {
        gameOver = false;
        snake = new Snake();
        token1 = new Token(snake);
        token2 = new Token(snake); 
    }

    public void keyPressed(KeyEvent e) {

        if (!snake.isMoving()) {
            if (e.getKeyCode() == KeyEvent.VK_UP || e.getKeyCode() == KeyEvent.VK_DOWN || e.getKeyCode() == KeyEvent.VK_RIGHT) {
                snake.setIsMoving(true);
            }
        }
        if (e.getKeyCode() == KeyEvent.VK_UP) {
            if (snake.getYDir() != 1) {
                snake.setYDir(-1);
                snake.setXDir(0);
            }
        }
        if (e.getKeyCode() == KeyEvent.VK_DOWN) {
            if (snake.getYDir() != -1) {
                snake.setYDir(1);
                snake.setXDir(0);
            }
        }
        if (e.getKeyCode() == KeyEvent.VK_LEFT) {
            if (snake.getXDir() != 1) {
                snake.setXDir(-1);
                snake.setYDir(0);
            }
        }
        if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
            if (snake.getXDir() != -1) {
                snake.setXDir(1);
                snake.setYDir(0);
            }
        }
        if (e.getKeyCode() == KeyEvent.VK_R) {
            restartGame();
//            String musicLocation = "E:\\Documents\\NetBeansProjects\\Snake\\Music\\Music1.wav";
//            mc.playMusic(musicLocation);
//            checkMusic = true;
        }
//        if (e.getKeyCode() == KeyEvent.VK_1) {
//            if (checkMusic == true) {
//                mc.stopMusic();
//            }
//            String musicLocation = "E:\\Documents\\NetBeansProjects\\Snake\\Music\\Music1.wav";
//            mc.playMusic(musicLocation);
//        }
//        if (e.getKeyCode() == KeyEvent.VK_2) {
//              if (checkMusic == true) {
//                mc.stopMusic();
//            }
//            String musicLocation = "E:\\Documents\\NetBeansProjects\\Snake\\Music\\Music2.wav";
//            mc.playMusic(musicLocation);
//        }
//        if (e.getKeyCode() == KeyEvent.VK_3) {
//             if (checkMusic == true) {
//                mc.stopMusic();
//            }
//            String musicLocation = "E:\\Documents\\NetBeansProjects\\Snake\\Music\\Music3.wav";
//            mc.playMusic(musicLocation);
//        }
//         if (e.getKeyCode() == KeyEvent.VK_P) {
//             mc.pauseMusic();
//         }
//           if (e.getKeyCode() == KeyEvent.VK_O) {
//             mc.resumeMusic();
//         }
    }
         

    public void keyReleased(KeyEvent e) {

    }

}
