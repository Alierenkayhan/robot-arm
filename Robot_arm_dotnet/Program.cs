using System;
using System.IO.Ports;
using System.Threading;

class Program
{
    static void Main(string[] args)
    {
        string portName = "COM3";  // Arduino'nun bağlı olduğu portu güncelle
        int baudRate = 9600;

        using (SerialPort arduino = new SerialPort(portName, baudRate))
        {
            arduino.Open();
            Console.WriteLine("Servo kontrol tuşları:\n" +
                "Servo 0: Q (ileri) / A (geri)\n" +
                "Servo 1: W (ileri) / S (geri)\n" +
                "Servo 2: E (ileri) / D (geri)\n" +
                "Servo 3: R (ileri) / F (geri)\n" +
                "Servo 4: T (ileri) / G (geri)\n" +
                "Servo 5: Y (ileri) / H (geri)\n" +
                "Servo 6: U (ileri) / J (geri)\n" +
                "Çıkmak için ESC'ye basın.");

            while (true)
            {
                if (Console.KeyAvailable)
                {
                    var key = Console.ReadKey(intercept: true).Key;

                    switch (key)
                    {
                        case ConsoleKey.Q: arduino.Write("Q"); break;
                        case ConsoleKey.A: arduino.Write("A"); break;
                        case ConsoleKey.W: arduino.Write("W"); break;
                        case ConsoleKey.S: arduino.Write("S"); break;
                        case ConsoleKey.E: arduino.Write("E"); break;
                        case ConsoleKey.D: arduino.Write("D"); break;
                        case ConsoleKey.R: arduino.Write("R"); break;
                        case ConsoleKey.F: arduino.Write("F"); break;
                        case ConsoleKey.T: arduino.Write("T"); break;
                        case ConsoleKey.G: arduino.Write("G"); break;
                        case ConsoleKey.Y: arduino.Write("Y"); break;
                        case ConsoleKey.H: arduino.Write("H"); break;
                        case ConsoleKey.U: arduino.Write("U"); break;
                        case ConsoleKey.J: arduino.Write("J"); break;
                        case ConsoleKey.Escape:
                            Console.WriteLine("Çıkış yapılıyor...");
                            return;
                    }
                }

                Thread.Sleep(100);
            }
        }
    }
}
