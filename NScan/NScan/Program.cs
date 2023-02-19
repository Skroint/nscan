// See https://aka.ms/new-console-template for more information
using Microsoft.Extensions.DependencyInjection;
using SharpPcap;




public class Program
{

    static IServiceProvider Services;

    static void PrintPortLine(int no, string ip, int port, string service)
    {
        Console.ForegroundColor = ConsoleColor.DarkYellow;
        Console.Write($"[{no}]");
        Console.ForegroundColor = ConsoleColor.Gray;
        Console.WriteLine($"\t{ip}\t{port}\t{service}");
     
    }
    static void Main(string[] args)
    {
        Console.WriteLine("No\tIP\t\tPort\tService");
        Console.WriteLine("-----------------------------------------------");
        Console.ForegroundColor = ConsoleColor.Magenta;
      //  Console.WriteLine("[192.168.1.2]");
        PrintPortLine(0, "192.168.1.2", 25, "SMTP");
        PrintPortLine(1, "192.168.1.2", 80, "HTTP");
        PrintPortLine(2, "192.168.1.2", 445, "SMB");
        Console.WriteLine();

        Console.ForegroundColor = ConsoleColor.Magenta;
   //     Console.WriteLine("[192.168.1.6]");
        PrintPortLine(0, "192.168.1.6", 80, "HTTP");
        PrintPortLine(1, "192.168.1.6", 445, "HTTPS");
        PrintPortLine(2, "192.168.1.6", 1433, "SQL");
        PrintPortLine(3, "192.168.1.6", 1677, "<Unknown>");
        PrintPortLine(4, "192.168.1.6", 1883, "MQTT");

        return;
        Services = ConfigureServices();


        Console.WriteLine("Hello, World!");

        var devices = CaptureDeviceList.Instance;
        foreach (var dev in devices)
        {
            Console.WriteLine("{0}\n", dev.ToString());
        
        }
        // var categories new MatSparCategoryListReader().Read();
        Console.ReadLine();



    }

  

    static IServiceProvider ConfigureServices()
    {
        var services = new ServiceCollection();


        //services.AddSingleton<CategoryListCreatorService>();
        //services.AddSingleton<CategoryCrawlerService>();
        //services.AddSingleton<ProductCrawlerService>();
        //services.AddSingleton<ConsoleTools>();
        //services.AddSingleton<ConfigService>();
        //services.AddSingleton<DatabaseService>();




        return services.BuildServiceProvider();
    }
}

