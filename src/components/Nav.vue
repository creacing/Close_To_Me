<template>
  <Neko :isShow="isShow" :isDark="isDark" />
  <div class="inner">
    <Brand />

    <nav class="nav" :class="navBtm === 2 ? '' : navBtm === 1 ? 'show down' : 'show up'">
      <div class="inner">
        <div class="toggle" :class="showIndex ? 'close' : ''" @click="showSide">
          <div class="lines" aria-label="切换导航栏">
            <span class="line"></span>
            <span class="line"></span>
            <span class="line"></span>
          </div>
        </div>
        <ul class="menu">
          <li class="item" :class="item.liClass" v-for="item in nav" :key="item">
            <RouterLink :to="item.link" :class="item.aClass" :rel="item.rel">
              <i class="ic" :class="item.iClass" v-if="item.iClass"></i>
              {{ item.name }}
            </RouterLink>
            <ul class="submenu" v-if="item.children.length > 0">
              <li class="item" v-for="child in item.children" :key="child">
                <RouterLink :to="child.link" :rel="child.rel" :class="child.iClass">
                  <i class="ic" :class="child.iClass"></i>
                  {{ child.name }}
                </RouterLink>
              </li>
            </ul>
          </li>
        </ul>
        <ul class="right">
          <li class="item theme">
            <i v-if="isDark" class="ic i-sun" @click="changeTheme" data-theme></i>
            <i v-if="!isDark" class="ic i-moon" @click="changeTheme" data-theme="dark"></i>
          </li>
          <li class="item search">
            <i class="ic i-search" @click="searchArticles"></i>
          </li>
        </ul>
      </div>
    </nav>
  </div>
  <BgImage />
  <Search :showSearch="showSearch" @close="closeSearchDialog" />
</template>
<script setup>
import { RouterLink } from "vue-router";
import Neko from "./Neko.vue";
import Search from "./Search.vue";
import config from "./../../public/config.js";
import Brand from "./Brand.vue";
import BgImage from "./BgImage.vue";
import { onMounted, ref, onUnmounted, toRefs, nextTick } from "vue";
import { store } from "@/stores/store.js";
import anime from "animejs/lib/anime.es.js";

const { nav } = config;
const state = store();

//切换黑白背景
const isDark = ref(true); // 白天黑夜 default 白天
const isShow = ref(false); // 是否显示 default 不显示
onMounted(() => {
  const hasSun = localStorage.getItem("isDark");
  const HTML = document.documentElement;
  //初始化读取localStorage数据 判断主题颜色
  if (hasSun) {
    isDark.value = Number(hasSun) === 0 ? false : true;
    state.isDark = isDark.value ? 1 : 0;

    if (!isDark.value) {
      HTML.setAttribute("data-theme", "dark");
    } else {
      HTML.setAttribute("data-theme", "");
    }
  }
});

const changeTheme = () => {
  const HTML = document.documentElement;

  isDark.value = !isDark.value;
  isShow.value = !isShow.value;
  //background color
  localStorage.setItem("isDark", isDark.value ? 1 : 0);
  state.isDark = isDark.value ? 1 : 0;
  if (!isDark.value) {
    HTML.setAttribute("data-theme", "dark");
  } else {
    HTML.setAttribute("data-theme", "");
  }
  // switch white and dark
  setTimeout(() => {
    isDark.value = !isDark.value;
  }, 200);
  //hidden animation ,stop for 2500ms
  setTimeout(() => {
    isShow.value = !isShow.value;
    isDark.value = !isDark.value;
  }, 2500);
};
//search component
const showSearch = ref(false);
const searchArticles = () => {
  showSearch.value = true;
};
const closeSearchDialog = (value) => {
  showSearch.value = value;
};

const navBtm = ref(2);
let scroll = 0;
let offsetWave = null;

onMounted(() => {
  offsetWave = document.getElementById("waves").offsetTop;
  window.addEventListener("scroll", scrollTop, true);
});

const scrollTop = () => {
  const newScroll =
    document.documentElement.scrollTop || document.body.scrollTop;

  if (newScroll > scroll) {
    //往下拉
    newScroll < offsetWave ? (navBtm.value = 2) : (navBtm.value = 1);
  } else {
    // 往上拉
    newScroll < offsetWave ? (navBtm.value = 2) : (navBtm.value = 0);
  }
  scroll = newScroll;
};

onUnmounted(() => {
  window.removeEventListener("scroll", scrollTop);
});
const { showIndex } = toRefs(state);

const showSide = () => {
  showIndex.value = !showIndex.value;

  // const side = document.getElementById("sidebar");
  // const sidebar = side ? side : document.getElementById("sideTool");

  // const animation = {
  //   begin: function (anim) {
  //     sidebar.style.display = "block";
  //   },
  //   translateX: [100, 0],
  //   opacity: [0, 1],
  // };

  // anime(
  //   Object.assign(
  //     {
  //       targets: sidebar,
  //       duration: 400,
  //       easing: "linear",
  //     },
  //     animation
  //   )
  // ).finished.then(function () {
  //   sidebar.style.display = "block";
  // });

  // const hiddenSidebar = (e) => {
  //   showIndex.value = false;

  //   const animation = {
  //     begin: function (anim) {},
  //     translateX: [0, 100],
  //     opacity: [1, 0],
  //   };

  //   anime(
  //     Object.assign(
  //       {
  //         targets: sidebar,
  //         duration: 200,
  //         easing: "linear",
  //       },
  //       animation
  //     )
  //   ).finished.then(function () {
  //     sidebar.style.display = "none";
  //   });

  //   // window.removeEventListener("click", hiddenSidebar);
  // };
  // const preventHidden = (e) => {
  //   e.stopPropagation();
  // };
  // window.addEventListener("click", hiddenSidebar);
  // sidebar.addEventListener("click", preventHidden);
};
</script>

<style lang="scss" scoped>
.nav {
  z-index: 998;
}

.nav .inner {
    height: 100%;
    display: flex;
    width: calc(100% - .625rem);
    flex-wrap: nowrap;
    margin: 0 auto;
    width: 100%
}

@media (min-width: 1200px) {
    .nav .inner {
        width:72.5rem
    }
}

@media (min-width: 1600px) {
    .nav .inner {
        width:73%
    }
}

.nav .toggle {
    display: none
}

@media (max-width: 991px) {
    .nav .toggle {
        display:flex;
        flex-direction: column;
        justify-content: center;
        align-items: center
    }
}

.nav .toggle .lines {
    padding: 1.25rem;
    width: 1.375rem;
    box-sizing: unset
}

.nav .menu {
    padding: .625rem 0;
    margin: 0;
    width: 100%
}

.nav .menu .item {
    display: inline-block;
    position: relative;
    padding: 0 .625rem;
    letter-spacing: .0625rem;
    text-align: center
}

@media (max-width: 767px) {
    .nav .menu .item {
        display:none
    }

    .nav .menu .item.title {
        display: block
    }
}

.nav .menu .item .ic {
    margin-right: .5rem
}

.nav .menu .item:not(.title) a {
    display: block;
    font-size: 1em
}

.nav .menu .item.active:not(.dropdown) a::before,.nav .menu .item:not(.dropdown):hover a::before {
    width: 80%
}

.nav .menu .submenu {
    display: none;
    position: absolute;
    margin-top: .5rem;
    padding: 0;
    width: -webkit-max-content;
    width: -moz-max-content;
    width: max-content;
    background-color: var(--grey-9-a5);
    box-shadow: 0 .3125rem 1.25rem -.25rem var(--grey-9-a1);
    border-radius: .625rem
}

.nav .menu .submenu::before {
    position: absolute;
    top: -1.25rem;
    left: 0;
    width: 100%;
    height: 2.5rem;
    content: ''
}

.nav .menu .submenu:hover {
    display: block
}

.nav .menu .submenu .item {
    display: block
}

.nav .menu .submenu .item a {
    display: inline-block;
    padding: .3rem .7rem;
    width: 100%;
    text-shadow: none
}

.nav .menu .submenu .item a::before {
    content: none
}

.nav .menu .submenu .item:hover a {
    transform: translateX(.3rem)
}

.nav .menu .submenu .item.active a,.nav .menu .submenu .item:hover a {
    opacity: 1
}

.nav .menu .item.dropdown>a::after {
    content: "";
    display: inline-block;
    margin-left: .3rem;
    vertical-align: middle;
    border: .3rem solid transparent;
    border-top-color: currentColor;
    border-bottom: 0
}

.nav .menu .item.dropdown:hover .submenu {
    display: block
}

.nav .right {
    display: inline-flex;
    align-items: center;
    justify-content: center
}

.nav .right .item {
    padding: .625rem .5rem;
    cursor: pointer
}

.nav .right .i-sun {
    font-size: 1.125em
}
</style>
