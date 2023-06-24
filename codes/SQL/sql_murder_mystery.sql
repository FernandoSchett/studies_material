-- SQL murder mystery problem: https://mystery.knightlab.com
-- Made by: https://github.com/FernandoSchett

--Check description from case at crime_scene_report
SELECT 
	*
FROM
	crime_scene_report c
WHERE
	c.type = "murder"
	AND
	c.date = "20180115"
	AND
	c.city = "SQL City"

-- Looking for 2 witnesses said at the description
-- 1
SELECT 
	*
FROM
	person p
WHERE
	p.name LIKE "Annabel%" 
	AND 
	p.address_street_name LIKE "Franklin Ave%"


--2
SELECT 
	*
FROM
	person p
WHERE
	p.address_street_name LIKE "Northwestern%"
ORDER BY p.address_number DESC


-- Loooking for witnesses interviews

SELECT 
	*
FROM
	interview i
WHERE
	i.person_id = 16371
	OR
	i.person_id = 14887

-- Finding the Murderer
SELECT
*
FROM
	get_fit_now_check_in gc,
	get_fit_now_member gm,
	drivers_license dl,
	person p
WHERE
	gc.membership_id = gm.id
	AND
	gc.membership_id LIKE "48Z%"
	AND 
	gm.membership_status = "gold"
	AND
	gc.check_in_date = 20180109
	AND
	dl.plate_number LIKE "%H42W%"
	AND
	gm.person_id = p.id
	AND
	p.license_id = dl.id

--Inserting the murder at the answers
INSERT INTO solution VALUES (1, 'Jeremy Bowers');        
    SELECT value FROM solution;

-- Looking for the REAL Villan:

-- Getting Jeremy Bowers ID:
SELECT
	*
FROM
	get_fit_now_member g
WHERE
	name = "Jeremy Bowers"

-- Looking for his interview:
SELECT
	*
FROM
	interview f
WHERE
	person_id = 67318

-- Getting the name of the REAL murderer based on interview:
SELECT
	*
FROM
	drivers_license dl,
	person p,
	facebook_event_checkin f
WHERE
	dl.gender = "female"
	AND
	dl.hair_color = "red"
	AND
	dl.car_model = "Model S"
	AND
	dl.car_make = "Tesla"
	AND
	dl.id = p.license_id
	AND
	p.id = f.person_id
	AND
	f.event_name = "SQL Symphony Concert"
	AND
	f.date > 20171200 
	AND
	f.date < 20180100

--Inserting the REAL murder at the answers
INSERT INTO solution VALUES (1, 'Miranda Priestly');        
    SELECT value FROM solution;


              



              


              




              
              
