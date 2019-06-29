int R[] = {2, 7, A5, 5, 13, A4, 12, A2};
int C[] = {6, 11, 10, 3, A3, 4, 8, 9};
char command_value = 0;
int maxArraySize = 7;
int col = 3;
int row = 3;
int beforeCol = row;
int beforeRow = col;


void setup()
{
  Serial.begin(9600);
  for (int i = 0; i <= maxArraySize; i++)
  {
    pinMode(R[i], OUTPUT);
    pinMode(C[i], OUTPUT);
  }
}




void loop()
{

  turnOn(col, row);
  if (Serial.available() > 0)
  {
    command_value = Serial.read();

    switch (command_value) {
      case '0':
        up();
        break;
      case '3':
        back();
        break;
      case '1':
        next();
        break;
      case '2':
        down();
        break;
    }
  }
}

void up() {
  if (row > 0) {
    row--;
  } else if (col == 0) {
    col = maxArraySize;
    row = maxArraySize;
  } else {
    row = maxArraySize;
    back();
  }
}

void back() {

  if (col > 0) {
    col--;
  } else if (row == 0) {
    col = maxArraySize;
    row = maxArraySize;
  } else {
    col = maxArraySize;
    up();
  }

}

void next() {
  if (col < maxArraySize) {
    col++;
  } else if (row == maxArraySize) {
    col = 0;
    row = 0;
  } else {
    col = 0;
    down();
  }
}

void down() {
  if (row < maxArraySize) {
    row++;
  } else if (col == maxArraySize) {
    row = 0;
    col = 0;
  } else {
    row = 0;
    next();
  }

}

void turnOn(int col, int row) {
  
  turnOff(beforeCol, beforeRow);
  for (int c = 0; c <= maxArraySize; c++)
  {
    if (c == col) {
      digitalWrite(C[c], LOW);
    } else {
      digitalWrite(C[c], HIGH);
    }


    for (int r = 0; r <= maxArraySize; r++)
    {
      if (r == row) {
        digitalWrite(R[r], HIGH);
      } else {
        digitalWrite(R[r], LOW);
      }
    }
  }
  
  beforeCol = col;
  beforeRow = row;
  
}

void turnOff(int col, int row)
{
    
    digitalWrite(R[row], LOW);
    digitalWrite(C[col], HIGH);  
}
