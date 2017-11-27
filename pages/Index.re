let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Index");

let make = (~items: Listings.items, _children) => {
  ...component,
  didMount: (_self) => [%bs.raw {|
  console.log('=>', items)
|}],
  render: (_self) =>
    <div>
      <Next.Head> <title> (str("Evergreen Roots")) </title> </Next.Head>
      <span> (str("Home | ")) </span>
      <Next.Link href="/contact"> <a> (str("Contact")) </a> </Next.Link>
      <About />
      (List.length(items) > 0 ? <Listings items /> : <Loading />)
    </div>
};

/* TODO: How should I convert JS array of items into Listings.items? */
let default =
  ReasonReact.wrapReasonForJs(
    ~component,
    (jsProps) => make(~items=Array.to_list(jsProps##items), [||])
  );
