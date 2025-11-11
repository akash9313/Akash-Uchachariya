import phonenumbers
from phonenumbers import geocoder, carrier
from opencage.geocoder import OpenCageGeocode
import folium

# Enter your API key here
OPENCAGE_API_KEY = 'YOUR_OPENCAGE_API_KEY'

# Enter the phone number you want to track
phone_number = "+919313357315"

# Parse the phone number
parsed_number = phonenumbers.parse(phone_number)

# Get the location description
location = geocoder.description_for_number(parsed_number, "en")
print(f"Location: {location}")

# Get the service provider
service_provider = carrier.name_for_number(parsed_number, "en")
print(f"Service Provider: {service_provider}")

# Initialize OpenCage geocoder
geocoder = OpenCageGeocode(OPENCAGE_API_KEY)

# Get the latitude and longitude of the location
results = geocoder.geocode(location)
if results:
    lat = results[0]['geometry']['lat']
    lng = results[0]['geometry']['lng']
    print(f"Latitude: {lat}, Longitude: {lng}")

    # Create a map centered around the location
    my_map = folium.Map(location=[lat, lng], zoom_start=10)

    # Add a marker to the map
    folium.Marker([lat, lng], popup=location).add_to(my_map)

    # Save the map to an HTML file
    my_map.save("location.html")
    print("Map has been saved to location.html")
else:
    print("Location not found")
