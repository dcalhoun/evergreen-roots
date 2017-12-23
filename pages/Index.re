let str = ReasonReact.stringToElement;

type action =
  | Loaded(ListingData.items)
  | Loading;

type state = {
  status: string,
  items: ListingData.items
};

let component = ReasonReact.reducerComponent("Index");

let make = (~items: ListingData.items, ~status: string, _children) => {
  let loadListings = ({ReasonReact.reduce}) => {
    ListingData.fetch(reduce((payload) => Loaded(payload))) |> ignore;
    reduce((_items) => Loading, items)
  };
  {
    ...component,
    initialState: () => {status, items},
    reducer: (action, state) =>
      switch action {
      | Loaded(items) =>
        ReasonReact.Update({...state, items, status: Status.fetched})
      | Loading => ReasonReact.Update({...state, status: Status.fetching})
      },
    didMount: (self) => {
      self.reduce((items) => Loaded(items), items);
      loadListings(self);
      ReasonReact.NoUpdate
    },
    render: (self) =>
      <div>
        <Next.Head> <title> (str("Evergreen Roots")) </title> </Next.Head>
        <span> (str("Home | ")) </span>
        <Next.Link href="/contact"> <a> (str("Contact")) </a> </Next.Link>
        <About />
        (
          self.state.status == Status.fetching ?
            <Loading /> : <Listings items=self.state.items />
        )
      </div>
  }
};

let default =
  ReasonReact.wrapReasonForJs(
    ~component,
    (jsProps) =>
      make(
        ~status=jsProps##status,
        ~items=jsProps##items |> ListingData.Decode.items,
        [||]
      )
  );
