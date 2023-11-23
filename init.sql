create table if not exists events (
    id serial primary key,
    title text not null,
    description text,
    begin_date timestamp not null,
    end_date timestamp,
    event_type text not null,
    constraint event_type_chk check (event_type in ('class', 'sport', 'other', 'upbringing'))
);
