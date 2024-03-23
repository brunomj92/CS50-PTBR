-- Keep a log of any SQL queries you execute as you solve the mystery.

-- First read about crimes ocurred at given date and street
SELECT description
FROM crime_scene_reports
WHERE street = 'Chamberlin Street' AND month = 07 AND day = 28;

-- Find out about the interviews mentioning the courthouse
SELECT transcript FROM interviews
WHERE transcript LIKE LOWER('%courthouse%') AND month = 07 AND day = 28;

-- Camera for the parking lot within 10 minutes of the theft -> 10:15am
-- Withdrew money in the morning
-- Phone call to other person who then bought a plane ticket

SELECT name, phone_calls.caller, phone_calls.receiver, phone_calls.day, phone_calls.duration, passengers.flight_id, passengers.seat, flights.month, flights.day, flights.hour, flights.minute, flights.origin_airport_id, airports.city, flights.destination_airport_id --, courthouse_security_logs.month, courthouse_security_logs.day, courthouse_security_logs.hour, courthouse_security_logs.minute
FROM people
JOIN phone_calls ON caller = phone_number
JOIN passengers ON passengers.passport_number = people.passport_number
--JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON airports.id = flights.origin_airport_id

WHERE phone_number IN
(SELECT caller FROM phone_calls
WHERE month = 07 AND day = 28 AND duration < 60) -- Short phone call that day

AND people.license_plate IN -- Cars leaving soon after theft
(SELECT courthouse_security_logs.license_plate FROM courthouse_security_logs
WHERE month = 07 AND day = 28 AND hour = 10 AND minute <= 25 AND activity = 'exit')

AND people.id IN -- Identifyer for transactions in ATM
(SELECT person_id FROM bank_accounts
WHERE bank_accounts.account_number IN
(SELECT atm_transactions.account_number
FROM atm_transactions
WHERE month = 07 AND day = 28 AND atm_location = 'Fifer Street' AND transaction_type = 'withdraw')) -- List of accounts that had transactions within parameters

AND people.passport_number IN (SELECT passengers.passport_number FROM passengers --List of passports leaving Fiftyville
--JOIN flights ON passengers.flight_id = flights.id
WHERE passengers.flight_id IN
(SELECT flights.id FROM flights
WHERE month = 07 AND day = 29 AND origin_airport_id = 8)) -- List of flights leaving Fiftyville
ORDER BY people.id ASC, phone_calls.day; -- Generated 2 suspects, one of them returned do Fiftyville the next day from Dubai (excluded)

SELECT * FROM people
WHERE phone_number IN
(SELECT receiver FROM phone_calls
WHERE month = 07 AND day = 28 AND duration < 60 AND caller = '(367) 555-5533'); -- Received short call from the main suspect at day and time

SELECT * FROM airports
WHERE id = 4 -- Main suspect's destination
