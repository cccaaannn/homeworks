from fastapi import FastAPI
import requests
from fastapi.middleware.cors import CORSMiddleware

app = FastAPI()

origins = ["*"]

app.add_middleware(
    CORSMiddleware,
    allow_origins=origins,
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

@app.get("/get_weather/{city}")
async def get_weather(city):
    response = requests.get(f"http://api.weatherstack.com/current?access_key=<key>&query={city}")
    if response.ok:
        return {"status": True, "message": "", "data": response.json()}
    else:
        return {"status": False, "message": "Server error", "data": None}