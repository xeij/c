import turtle
import colorsys

t = turtle.Turtle()
s = turtle.Screen().bgcolor('black')

t.speed(50000)
n = 7000
h = 20

for i in range(720):
    c = colorsys.hsv_to_rgb(h, 1, 0.8)
    h+= 1/n
    t.color(c)
    t.left(2)
    t.fd(22)
    for j in range(20):
        t.left(50)
        t.circle(170)