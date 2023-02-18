// See https://aka.ms/new-console-template for more information
using Microsoft.Extensions.DependencyInjection;
using SharpPcap;




public class Program
{

    static IServiceProvider Services;


    static void Main(string[] args)
    {
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

