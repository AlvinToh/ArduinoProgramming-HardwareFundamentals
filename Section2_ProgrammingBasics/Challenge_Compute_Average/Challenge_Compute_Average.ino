//const int len = 10;
//int a[len] = {0, 2, -4, 12, -52, 42, -96, 7, -23, 99};

const int len = 8;
int a[len] = {125, 1920, 503, 299, 67, 13578, 7632, 22043};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  float result = 0;
  for(int i = 0; i < len; i++) {
    result += a[i];
  }
  result /= len;
  Serial.println(result, 4);
}

void loop() {
  // put your main code here, to run repeatedly:

}
