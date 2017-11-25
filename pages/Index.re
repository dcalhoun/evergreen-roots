let str = ReasonReact.stringToElement;

type state = {items: Listings.items};

let component = ReasonReact.reducerComponent("Index");

let make = (_children) => {
  ...component,
  /* getInitialProps: () =>
     resp = await fetchListings();
     json = await resp.json();
     { items: json.results }; */
  initialState: () => {items: [{listing_id: 1, price: 10, title: "Hello"}]},
  reducer: ((), _) => ReasonReact.NoUpdate,
  render: ({state: {items}}) =>
    <div>
      <span> (str("Home")) </span>
      <About />
      (List.length(items) > 0 ? <Listings items /> : <Loading />)
    </div>
};

let jsComponent =
  ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
