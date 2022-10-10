<template>
  <Neko :isShow="isShow" :isSun="isSun" />
  <div class="inner">
    <Brand />

    <nav id="nav" :class="navBottom === 2 ? '' : navBottom === 1 ? 'show down' : 'show up'">
      <div class="inner">
        <div class="toggle" :class="isSidebar ? 'close' : ''" @click.stop="showSidebar">
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
            <i v-if="isSun" class="ic i-sun" @click="changeTheme" data-theme></i>
            <i v-if="!isSun" class="ic i-moon" @click="changeTheme" data-theme="dark"></i>
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
const isSun = ref(true); // 白天黑夜 default 白天
const isShow = ref(false); // 是否显示 default 不显示
onMounted(() => {
  const hasSun = localStorage.getItem("isSun");
  const HTML = document.documentElement;
  //初始化读取localStorage数据 判断主题颜色
  if (hasSun) {
    isSun.value = Number(hasSun) === 0 ? false : true;
    state.isSun = isSun.value ? 1 : 0

    if (!isSun.value) {
      HTML.setAttribute("data-theme", "dark");
    } else {
      HTML.setAttribute("data-theme", "");
    }
  }
});

const changeTheme = () => {
  const HTML = document.documentElement;

  isSun.value = !isSun.value;
  isShow.value = !isShow.value;
  //background color
  localStorage.setItem("isSun", isSun.value ? 1 : 0);
  state.isSun = isSun.value ? 1 : 0
  if (!isSun.value) {
    HTML.setAttribute("data-theme", "dark");
  } else {
    HTML.setAttribute("data-theme", "");
  }
  // switch white and dark
  setTimeout(() => {
    isSun.value = !isSun.value;
  }, 200);
  //hidden animation ,stop for 2500ms
  setTimeout(() => {
    isShow.value = !isShow.value;
    isSun.value = !isSun.value;
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

const navBottom = ref(2);
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
    newScroll < offsetWave ? (navBottom.value = 2) : (navBottom.value = 1);
  } else {
    // 往上拉
    newScroll < offsetWave ? (navBottom.value = 2) : (navBottom.value = 0);
  }
  scroll = newScroll;
};

onUnmounted(() => {
  window.removeEventListener("scroll", scrollTop);
});

const { isSidebar } = toRefs(state);
const showSidebar = () => {
  isSidebar.value = true;

  const sidebar = document.getElementById("sidebar");
  const animation = {
    begin: function (anim) {
      sidebar.style.display = "block";
    },
    translateX: [100, 0],
    opacity: [0, 1],
  };

  anime(
    Object.assign(
      {
        targets: sidebar,
        duration: 400,
        easing: "linear",
      },
      animation
    )
  ).finished.then(function () {
    sidebar.style.display = "block";
  });
  const hiddenSidebar = (e) => {
    isSidebar.value = false;

    const animation = {
      begin: function (anim) { },
      translateX: [0, 100],
      opacity: [1, 0],
    };

    anime(
      Object.assign(
        {
          targets: sidebar,
          duration: 200,
          easing: "linear",
        },
        animation
      )
    ).finished.then(function () {
      sidebar.style.display = "none";
    });

    window.removeEventListener("click", hiddenSidebar);
  };
  const preventHidden = (e) => {
    e.stopPropagation();
  }
  window.addEventListener("click", hiddenSidebar);
  sidebar.addEventListener('click', preventHidden)
};
</script>

<style lang="scss" scoped>
</style>
