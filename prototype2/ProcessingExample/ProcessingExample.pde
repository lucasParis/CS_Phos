import codeanticode.syphon.*;

SyphonServer server;

void settings() {
  size(18,396, P3D);
  PJOGL.profile=1;
}

void setup() {
  // Create syhpon server to send frames out.
  server = new SyphonServer(this, "Processing Syphon");
}

void draw() {
  background(127);
  lights();
  translate(width/2, height/2);
  rotateX(frameCount * 0.01);
  rotateY(frameCount * 0.01);  
  box(150);
  server.sendScreen();
}

void stop()
{
  super.exit();
  println("sdfsdf");
}