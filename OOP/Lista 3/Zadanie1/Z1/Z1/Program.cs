using System;

namespace Z1
{
    /*
    Creator: dla klasy ServerA stworzyłem fabrykę, dzięki czemu implementacja tworzenia obiektów
    typu ServerA została oddzielona od kodu klienckiego. 

    Polymorphism: klasa ServerB, dziedzicząca po klasie ServerA, nadpisuję metodę IsConnected. 

    Pure fabrication: implementację generowania tokenu dla ServerB wyciągnąłem do osobnej klasy -
    CredentialsGenerator. Dzięki temu pozbywam się dodatkowej odpowiedzialności po stronie ServerB. 

    High cohesion: klasy są spójne, metody są ze sobą związane. 
    */
    public class ServerResponse
    {
        public int statusCode; 
        public string message;

        public ServerResponse(int statusCode, string message)
        {
            this.statusCode = statusCode;
            this.message = message;
        }
    }

    public class CredentialsGenerator
    {
        public string GenerateToken()
        {
            return "token";
        }
    }

    public class ServerA
    {
        public string address { get; private set; }

        public ServerA()
        {
            this.address = "xyz";
        }

        private ServerResponse DoRequest()
        {
            return new ServerResponse(200, "success");
        }

        public virtual bool IsConnected()
        {
            ServerResponse response = DoRequest();
            return response.statusCode == 200;
        }
    }

    public class ServerB: ServerA   
    {
        private CredentialsGenerator credentialsGenerator;

        public ServerB()
        {
            this.credentialsGenerator = new CredentialsGenerator();
        }

        private ServerResponse DoRequest(string token)
        {
            if(token != null)
            {
                return new ServerResponse(200, "success");
            }
            else
            {
                return new ServerResponse(400, "");
            }
        }

        public override bool IsConnected()
        {
            string token = this.credentialsGenerator.GenerateToken();
            ServerResponse response = this.DoRequest(token);
            return response.statusCode == 200;
        }
    }

    public class FactoryOfServerA
    {
        public ServerA Create()
        {
            return new ServerA();
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
        }
    }
}